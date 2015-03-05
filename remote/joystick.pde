interface PLabBridge {
  public int getWidth ();
  public int getHeight ();
  public void write (String string);
  public void subscribeRead (PLabRead sub);
  public void subscribeError (PLabRead sub);
  public void disconnect();
}
interface PLabRead {
  public void read(String string);
}
private PLabBridge pBridge;

void bindPLabBridge (PLabBridge bridge) {
  pBridge = bridge;
  size (bridge.getWidth (), bridge.getHeight ());
  
  update ();
}

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
  
  public String getValues() {
    String value = getLeftSpeed()+":"+getRightSpeed();
    return value;
  }
  
  /*public String getValues() {//Binary string: 0|0000|0|0000 => forward (1) / backwards (0)|left speed|forward (1) / backwards (0)|right speed
    int leftSpeed = getLeftSpeed();
    int rightSpeed = getRightSpeed();
    short value = (short)((leftSpeed >= 0) ? 1<<9|leftSpeed<<5 : abs(leftSpeed)<<5);
    value |= (short)((rightSpeed >= 0) ? 1<<4|rightSpeed : 0<<4|abs(rightSpeed));
    return "Test:Whoohoo";
  }*/
  
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
    ellipse((relX / ratio) + offsetX, (relY / ratio) + offsetY, 20, 20);
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

JoyStick joyStick;

void setup () {
  joyStick = new JoyStick(250, 6, 30, 110);
  
  size (240, 360);
}

void draw () {
  if (pBridge != null) {
    update ();
  }
  background (#303030);
  
  joyStick.draw();
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

void update () {
  if (joyStick.hasChanged()) {
    joyStick.resetChanged();
    String val = joyStick.getValues();
    //println(val);
    if (pBridge != null) {
      pBridge.write (val);
    }
  }
}
