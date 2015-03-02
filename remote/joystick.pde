interface PLabBridge {
  public int getWidth();
  public int getHeight();
  public void write (short binString);
  public void subscribeRead (PLabRead sub);
  public void subscribeError (PLabRead sub);
  public void disconnect();
}
interface PLabRead {
  public void read(short binString);
}
private PLabBridge pBridge;

public class JoyStick {
  private float ratio;//Used to get the correct coordinate in joystick according to step size
  private float offsetX, offsetY;//Offset from world origo to joystick origo
  private float size, posX, posY; //World coordinates for possition  of joystick (top corner) and size being both length and width
  private int relX, relY;//Relative coordinates inside the joystick area
  private boolean changed = true;

  public JoyStick (float size, float step, float posX, float posY) {
    this.size = size;
    this.posX = posX;
    this.posY = posY;
    offsetX = posX + (size / 2);
    offsetY = posY + (size / 2);
    ratio = step / size;
  }
  
  public void drag (float x, float y) {//Takes in world coordinates
    int newX = relativeX(x);
    int newY = relativeY(y);
    boolean inArea = (x >= posX && x <= (posX + size)) && (y >= posY && y <= (posY + size)); 
    if (inArea && (relX != newX || relY != newY)) {//If in area and different coordinates from last time
      relX = newX;
      relY = newY;
      changed = true;
    }
  }
  
  public void reset() {
    relX = 0;
    relY = 0;
    changed = true;
  }
  
  public void resetChanged() {
    changed = false;
  }
  
  public boolean hasChanged() {
    return changed;
  }
  
  public short getValues() {//Binary string: 0|0000|0|0000 => forward (1) / backwards (0)|left speed|forward (1) / backwards (0)|right speed
    int leftSpeed = getLeftSpeed();
    int rightSpeed = getRightSpeed();
    short value = (short)((leftSpeed >= 0) ? 1<<9|leftSpeed<<5 : abs(leftSpeed)<<5);
    value |= (short)((rightSpeed >= 0) ? 1<<4|rightSpeed : 0<<4|abs(rightSpeed));
    return value;
  }
  
  public int getLeftSpeed() {//Public while testing
    int halt = (relX < 0) ? abs(relX) : 0;
    float step = (ratio * size / 2);
    return (relY != 0) ? round((halt * (relY/step)) - relY) : relX;
  }
  
  public int getRightSpeed() {//Public while testing
    int halt = (relX >= 0) ? relX : 0;
    float step = (ratio * size / 2);
    return (relY != 0) ? round((halt * (relY/step)) - relY) : -relX;
  }
  
  public void draw () {
    stroke(#0699c4);
    fill(#023554);
    rect(posX, posY, size, size);
    stroke(#006987);
    line(posX + (size / 2), posY, posX + (size / 2), posY + size);
    line(posX, posY + (size / 2), posX + size, posY + (size / 2));
    ellipse((relX / ratio) + offsetX, (relY / ratio) + offsetY, 10, 10);
  }
  
  private String binPadding(String binString) {
    return String.format("%4s", binString).replace(' ', '0');
  }
  
  private int relativeX(float coord) {
    int newCoord = round((coord - offsetX) * ratio);
    return newCoord;
  }
  
  private int relativeY(float coord) {
    int newCoord = round((coord - offsetY) * ratio);
    return newCoord;
  }
}

//Injects the javascript interface with the processing code
void bindPLabBridge(PLabBridge bridge) {
  // Bind the bridge to the instance
  pBridge = bridge;
  // Set the size based on window size
  size (bridge.getWidth(), bridge.getHeight());
  update();
}

JoyStick joyStick;

// setup() is only used for testing purposes
void setup () {
  joyStick = new JoyStick(200, 30, 18, 70);
  size(240, 360);
}

//Main loop
void draw() {
  // If the bridge is set, run update. This will send the states to the arduino
  if (pBridge != null) {
    update ();
  }
  update();//Should be removed when not testing
  background(#303030);
  joyStick.draw();
}

//update() checks if the elements have changed and sends the info on to the framework
void update() {
  if (joyStick.hasChanged()) {
    joyStick.resetChanged();
    if (pBridge != null) {
      pBridge.write(joyStick.getValues());
    }
    //Testing data:
    println(Integer.toBinaryString(joyStick.getValues()));
    println(joyStick.getLeftSpeed());
    println(joyStick.getRightSpeed());
    println("-----------");
  }
}

void mouseDragged() {
  joyStick.drag(mouseX, mouseY);
}

void mousePressed() {
  joyStick.drag(mouseX, mouseY);
}

void mouseReleased() {
  joyStick.reset();
}
