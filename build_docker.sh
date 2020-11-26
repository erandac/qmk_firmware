#docker run -e keymap=erandac  -e subproject= -e keyboard=ergodox_ez --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
git submodule update --recursive --remote
util/docker_build.sh ergodox_ez:erandac
./teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_erandac.hex
