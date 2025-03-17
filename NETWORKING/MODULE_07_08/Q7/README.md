# Configure Management VLAN and Test SSH/Telnet Access in Packet Tracer

This guide explains how to configure a management VLAN, assign an IP address, and test SSH/Telnet access to a switch in Cisco Packet Tracer.

---

## 1. Network Topology

### Devices:
- **1 Switch** (e.g., Cisco Catalyst 2960).
- **1 PC** (for configuration and testing).

### Connections:
- **PC ↔ Switch**: Use a **copper straight-through cable**.
- Connect the **PC** to the **FastEthernet Port** on the switch.

![Setup](images/1.%20Setup.png)

---

## 2. IP Addressing

| Device            | Interface       | IP Address     | Subnet Mask     |
|-------------------|-----------------|----------------|-----------------|
| Switch (VLAN 10)  | VLAN Interface  | 192.168.1.1    | 255.255.255.0   |
| PC                | NIC             | 192.168.1.2    | 255.255.255.0   |

---

## 3. Configuration Steps

### **Step 3.1: Configure the Management VLAN**
1. Access the switch CLI:
```bash
   enable
   configure terminal
```
---

2. Create a VLAN for management:
```bash
    vlan 10
    name Management
    exit
```
---

3. Assign an IP address to the VLAN:
```bash
    interface vlan 10
    ip address 192.168.1.1 255.255.255.0
    no shutdown
    exit
```
---

4. Assign switch ports to VLAN 10:
```bash
    interface fa0/1
    switchport access vlan 10
    switchport mode access
    exit
```
---

### **Step 3.2: Configure SSH Access**
```bash
    enable
    configure terminal
    hostname Switch0
    ip domain-name example.com
    crypto key generate rsa
    username admin privilege 15 secret password123
    line vty 0 4
    transport input ssh
    login local
    end
```
![Config](images/2.%20Switch0.png)

---

### **Step 3.3: Configure the PC**
1. IP Address: 192.168.1.2
2. Subnet Mask: 255.255.255.0
3. Default Gateway: 192.168.1.1

---

## 4. Testing the Configuration

1. Ping:
```bash
    ping 192.168.1.1
```
![Ping](images/3.%20Ping.png)

---

2. SSH test:
```bash
    ssh -l admin 192.168.1.1
```
![SSH](images/4.%20SSH.png)

---

3. Telnet test:

Switch config:
```bash
    line vty 0 4
    transport input telnet ssh
```

PC0:
```bash
    telnet 192.168.1.1
```
---

SSH is used for for secure communication (encrypted), while Telnet can only be used in trusted environments.