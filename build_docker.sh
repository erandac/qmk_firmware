docker run -e keymap=erandac  -e subproject= -e keyboard=ergodox_ez --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
./teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_erandac.hex