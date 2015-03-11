# Dora
Dora the explorer!

## Beskrivelse (Description)  
> En Arduino Uno på en Zumo-robot, for å konkurrere på en sort skive med hvite kanter.  

> English: An Arduino Uno on a Zumo robot, to compete on a black disc with white trim/edge.

# Resultat etter kamp:
* Kvartfinale i autonom
 * 11 vinn, 2 tap i autonom? Ubeseiret frem til vi ble slått ut iallefall.
* Åttendedelsfinale i fjernstyrt.

# Taktikk 

* Hastighet  
 * Finn motstanderen raskt  
 * Beveg deg raskt  
* Oversikt  
 * Vit om du er ved streken  
 * Vit hvor motstanderen er  
 * Vit om man blir dyttet  
 

# Statistikk

### Rotasjon
(-250, 250) : 1s på 360
(-300, 300) : 0.86 på 360

### Dytting 
400 gir litt hopping, men funker greit


--------------------
# Pins
| Pinne | Navn                   |
|-------|------------------------|
|  3    | Ultrasound-1 echo      |
|  4    | Ultrasound-1 trigger   |
|  5    | Ultrasound-2 echo      |
|  6    | Ultrasound-2 trigger   |
| 12    | Zumo button            |

--------------------
# Tilstander og pseudokode

### Tilstander  

| Tilstand    | Input                             | Autonom |
|-------------|-----------------------------------|---------|
| Start       | Knapp                             | :white_check_mark: |
| Kalibrer    | knapp                             | :white_check_mark: |
| Søk         | funnet, ikke funnet, linje funnet | :white_check_mark: |
| Funnet      | mistet, linje funnet              | :white_check_mark: |
| Unnamanøver | tid, linje funnet                 | :white_check_mark: |

<img src="img/tilstandsdiagram.jpg" />

### Pseudokode  

> \# er metode, > er tilstand.  

**>Start**  
```
Sett fart 0
Hvis knapp:
>Kalibrer
```

**>Kalibrer**  
```
Sett fart 0
begin:
Roter litt
Kalibrer sensor
Loop x ganger fra 'begin'
Hvis knapp:
    >Søk
```

**>Søk**  
```
Sett fart 0
begin:
Les inn sensor
Tolk data
Hvis linje funnet:
	>Unnamanøver
Hvis funnet:
    Stop rotasjon
    >Funnet
#Roter
Loop uendelig fra 'begin'
```

**>Funnet**  
```
Sett fart frem
Les inn sensor
Hvis linje oppdaget:
	>Rygger
Hvis mistet:
	>Søk
Juster retning
```

**>Rygger**  
```
Sett fart bakover
Vent 'ryggetid'
>Søk
```

**>Unnamanøver**  
```
Les inn sensor
Finn siden linjen er nermest
Rygg bakover, størst fart bakover på siden som linjen er på
```

**#Roter**
```
Hvis bil er sett tidligere:
	sett 'retinng' til den siden bilen ble sett
Ellers:
	sett retning 'høyre'
Start rotering i 'retning'
>Søk
```
