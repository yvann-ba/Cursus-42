#!/bin/bash

arch=$(uname -a)

cpu_physical=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
cpu_virtual=$(grep "processor" /proc/cpuinfo | wc -l)

mem_total=$(free -m | awk '$1 == "Mem:" {print $2}')
mem_used=$(free -m | awk '$1 == "Mem:" {print $3}')
mem_usage_percent=$(free | awk '$1 == "Mem:" {printf("%.2f", $3/$2*100)}')

disk_total=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{total += $2} END {print total}')
disk_used=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{used += $3} END {print used}')
disk_usage_percent=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{used += $3} {total+= $2} END {printf("%d", used/total*100)}')

cpu_load=$(mpstat | grep all | awk '{print 100 - $13}')

last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4}')

lvm_check=$(lsblk | grep -q "lvm"; if [ $? -eq 0 ]; then echo yes; else echo no; fi)

tcp_connections=$(ss -t | grep ESTAB | wc -l)

user_log=$(who | wc -l)

network_ip=$(hostname -I | xargs)
network_mac=$(ip link | awk '/ether/ {print $2}' | head -1)

sudo_commands=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

{
  echo "Architecture: $arch"
  echo "CPU Physical: $cpu_physical"
  echo "vCPU: $cpu_virtual"
  echo "Memory Usage: $mem_used/${mem_total}MB ($mem_usage_percent%)"
  echo "Disk Usage: $disk_used/${disk_total}GB ($disk_usage_percent%)"
  echo "CPU Load: $cpu_load%"
  echo "Last Boot: $last_boot"
  echo "LVM in use: $lvm_check"
  echo "TCP Connections: $tcp_connections ESTABLISHED"
  echo "Logged in Users: $user_log"
  echo "Network: IP $network_ip, MAC $network_mac"
  echo "Sudo Commands Executed: $sudo_commands"
} | wall

