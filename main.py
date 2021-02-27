import serial
import keyboard
import termios, sys, os
dev = serial.Serial("/dev/ttyUSB0",9600)
cad = 0
TERMIOS = termios
SI=1
NO=0

def getkey():
	fd = sys.stdin.fileno()
	old = termios.tcgetattr(fd)
	new = termios.tcgetattr(fd)
	new[3] = new[3] & ~TERMIOS.ICANON & ~TERMIOS.ECHO
	new[6][TERMIOS.VMIN] = 1
	new[6][TERMIOS.VTIME] = 0
	termios.tcsetattr(fd, TERMIOS.TCSANOW, new)
	c = None
	try:
		c=str(os.read(fd,4))
		
	finally:
		termios.tcsetattr(fd, TERMIOS.TCSAFLUSH, old)
		
	c_Longitud=len(c)
	if(c=="b'\\x1b'"):
		c="[ESC]"
	if(c=="b'\\x1b[A'"):
		c="[CURSOR_ARRIBA]"
	if(c=="b'\\x1b[B'"):
		c="[CURSOR_ABAJO]"
	if(c=="b'\\x1b[D'"):
		c="[CURSOR_IZQUIERDA]"
	if(c=="b'\\x1b[C'"):
		c="[CURSOR_DERECHA]"
	if(c=="b'\\n'"):
		c="[INTRO]"
	if(c=="b'\\t'"):
		c="[TAB]"
	#print(c,"          ") # Para Latinoamerica
	if(c=="b'\\x1bOP'"):
		c="[F1]"
	if(c=="b'\\x1bOQ'"):
		c="[F2]"
	if(c=="b'\\x1bOR'"):
		c="[F3]"
	if(c=="b'\\x1bOS'"):
		c="[F4]"
	if(c=="b'\\x1b[15'"):
		c="[F5]"
	if(c=="b'\\x1b[17'"):
		c="[F6]"
	if(c=="b'\\x1b[18'"):
		c="[F7]"
	if(c=="b'\\x1b[19'"):
		c="[F8]"
	if(c=="b'\\x1b[20'"):
		c="[F9]"
	if(c=="b'\\x1b[21'"):
		c="[F10]"
	if(c=="b'\\x1b[23'"):
		c="[F11]"
	if(c=="b'\\x1b[24'"):
		c="[F12]"
	if(c=="b'\\x7f'"):
		c="[BORRAR]"
	if(c=="b'\\x1b[3~'"):
		c="[SUPRIMIR]"
	if(c=="b'\\x1b[H'"):
		c="[INICIO]"
	if(c=="b'\\x1b[F'"):
		c="[FIN]"
	if(c=="b'\\x1b[5~'"):
		c="[RePag]"
	if(c=="b'\\x1b[6~'"):
		c="[AvPag]"
	if(c=="b'\\x1b[2~'"):
		c="[INSERTAR]"
	if(c=="b'\\xc3\\x91'"):
		c="[Ñ]"
	if(c=="b'\\xc3\\xb1'"):
		c="[ñ]"
	if(c=="b'\\xc2\\xbf'"):
		c="[¿]"
	if(c=="b'\\xc2\\xa1'"):
		c="[¡]"
	if(c=="b'\\xc3\\xa7'"):
		c="[ç]"
	if(c=="b'\\xc3\\x87'"):
		c="[Ç]"

	#print(c_Longitud)
    
	if(c_Longitud==4):
		c="["+c[2]+"]"

	if(c=="[ ]"):
		c="[ESPACIO]"
        
	return c
	
Ejecutar=SI
print("\033c\033[3J") # Limpia La Pantalla De La Terminal
print("\033[?25l") # Oculta El Cursor
print("\033[0;0H", end="") # Coloca el cursor al inicio
print("DIRECIONES")
#os.system("tput civis") 
while Ejecutar:
	Tecla=getkey()
	print("\033[0;0H", end="")
	if(Tecla=="[SPACE]"):
		Ejecutar=NO
		cad="0"
	if(Tecla=="[w]"):
		cad="1"
		print(cad)
	if(Tecla=="[s]"):
		cad="5"
		print(cad)
	if(Tecla=="[d]"):
		cad="3"
		print(cad)
	if(Tecla=="[a]"):
		cad="7"
		print(cad)
	if(Tecla=="[q]"):
		cad="2"
		print(cad)
	if(Tecla=="[e]"):
		cad="8"
		print(cad)
	if(Tecla=="[z]"):
		cad="4"
		print(cad)
	if(Tecla=="[x]"):
		cad="6"
		print(cad)
	if(Tecla=="[0]"):
		cad="0"
	dev.write(cad.encode('ascii'))
print(cad)
print("Pulsa una tecla para finalizar...")
Tecla=getkey()
print("\033[?25h")	# Show the cursor
quit()
dev.close()
