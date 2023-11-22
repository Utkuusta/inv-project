#!/bin/bash

# Connect to a Wi-Fi network
WPA_CLI_PATH="/usr/sbin/wpa_cli"
$WPA_CLI_PATH -i wlan0 <<EOF
scan
scan_results
remove_network 0
add_network
set_network 0 ssid "Devinno"
set_network 0 psk "MehDil!1988"
enable_network 0
save_config
quit
EOF

# Other commands can be added as needed
