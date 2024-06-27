TITLE = RL78_Sample3
INC = include
SRC = src
OBJ = obj

CC = ccrl.exe
RA = asrl.exe
LK = rlink.exe
OC = oc78K0r.exe

OBJS = \
	$(OBJ)\main.obj	\
	$(OBJ)\common.obj	\
	$(OBJ)\timer.obj	\
	$(OBJ)\int.obj	\
	$(OBJ)\port.obj	\
	$(OBJ)\watchdogtimer.obj	\
	$(OBJ)\system.obj	\
	$(OBJ)\systeminit.obj	\
	$(OBJ)\panel.obj	\
	$(OBJ)\digitalio.obj

GOAL : RL78_Sample3.hex

$(OBJ)\main.obj : $(SRC)\main.c
	$(CC) -subcommand=main.pcc
$(OBJ)\common.obj : $(SRC)\common.c
	$(CC) -subcommand=common.pcc
$(OBJ)\timer.obj : $(SRC)\timer.c
	$(CC) -subcommand=timer.pcc
$(OBJ)\int.obj : $(SRC)\int.c
	$(CC) -subcommand=int.pcc
$(OBJ)\port.obj : $(SRC)\port.c
	$(CC) -subcommand=port.pcc
$(OBJ)\watchdogtimer.obj : $(SRC)\watchdogtimer.c
	$(CC) -subcommand=watchdogtimer.pcc
$(OBJ)\system.obj : $(SRC)\system.c
	$(CC) -subcommand=system.pcc
$(OBJ)\systeminit.obj : $(SRC)\systeminit.c
	$(CC) -subcommand=systeminit.pcc
$(OBJ)\panel.obj : $(SRC)\panel.c
	$(CC) -subcommand=panel.pcc
$(OBJ)\digitalio.obj : $(SRC)\digitalio.c
	$(CC) -subcommand=digitalio.pcc
RL78_Sample3.hex : $(OBJS)
	$(LK) -SUbcommand=RL78_Sample3.plk
