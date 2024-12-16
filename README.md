# PMP-esp32c3-baremetal

Implémentation du Physical Memory Protection (PMP) 🔒 en mode NAPOT de RISC-V en bare-metal sur le microcontrôleur ESP32C3.
Fait sur une machine virtuelle Ubuntu 20.04.6 avec Oracle VM VirtualBox 7.0.18

## Installer la toolchain
```bash
wget -O get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
python3 get-platformio.py
```
```bash
echo "export PATH=$PATH:$HOME/.local/bin" >> ~/.bashrc
ln -s ~/.platformio/penv/bin/platformio ~/.local/bin/platformio
ln -s ~/.platformio/penv/bin/pio ~/.local/bin/pio
ln -s ~/.platformio/penv/bin/piodebuggdb ~/.local/bin/piodebuggdb
```
```bash
pio pkg install --global --tool "espressif/toolchain-riscv32-esp"
```
```bash
echo "export PATH='$HOME/.platformio/packages/toolchain-riscv32-esp/bin:$PATH'" >> ~/.bashrc
echo "export PORT=/dev/ttyUSB0" >> ~/.bashrc
source ~/.bashrc
```
```bash
curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/develop/platformio/assets/system/99-platformio-udev.rules | sudo tee /etc/udev/rules.d/99-platformio-udev.rules
sudo service udev restart
```

## Lancer le programme sur l'ESP32C3

Attention : Sur VirtualBox, activer le contrôleur USB 3.0 (xHCI)
```
make flash monitor
```

