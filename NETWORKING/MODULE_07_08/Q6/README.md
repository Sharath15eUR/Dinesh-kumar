# VLAN Trunk Configuration with Native VLAN Changes

## Objective
This guide demonstrates how to change the native VLAN on a trunk port, test for VLAN mismatches, and troubleshoot connectivity issues in Cisco Packet Tracer.

---

## Network Setup

### Devices Needed
1. **2 Switches** (Switch 1 and Switch 2).
2. **2 PCs** (1 PC in each VLAN for testing purposes).
3. **Connection Medium**:
   - **Copper straight-through cables**: Connect PCs to switches.
   - **Crossover cable**: Connect Switch 1 to Switch 2.

![Setup](images/1.%20Setup.png)

---

### Network Connections
- **Switch 1**:
  - `FastEthernet 0/1`: Connect to **PC0** (VLAN 10).
  - `FastEthernet 0/24`: Connect to Switch 2 (`FastEthernet 0/24`).

- **Switch 2**:
  - `FastEthernet 0/1`: Connect to **PC1** (VLAN 10).
  - `FastEthernet 0/24`: Connect to Switch 1 (`FastEthernet 0/24`).

---

### IP Configuration for PCs
Each PC is assigned an IP address within VLAN 10:
- **PC0**: `192.168.10.2/24`
- **PC1**: `192.168.10.3/24`

---

## Configuration Steps

### Step 1: Create VLAN 10 on Both Switches
1. Access the CLI of each switch.
2. Create VLAN 10:
```bash
   enable
   configure terminal
   vlan 10
   name VLAN10
   exit
```
---

### Step 2: Assign Access Ports
1. On Switch 0, assign ports to VLANs:
```bash
    interface fastethernet 0/1
    switchport mode access
    switchport access vlan 10
    exit
```
2. On Switch 1, assign ports to VLANs:
```bash
    interface fastethernet 0/1
    switchport mode access
    switchport access vlan 10
    exit
```
---

### Step 3: Configure Trunk Ports
1. On Switch 0:
```bash
    interface fastethernet 0/24
    switchport mode trunk
    exit
```
2. On Switch 1:
```bash
    interface fastethernet 0/24
    switchport mode trunk
    exit
```

---

### Step 4: Change the Native VLAN on the Trunk Port
The default native VLAN on a trunk port is VLAN 1. Change it to VLAN 70:

1. On Switch 0:
```bash
    interface fastethernet 0/24
    switchport trunk native vlan 70
    exit
```
2. On Switch 1:
```bash
    interface fastethernet 0/24
    switchport trunk native vlan 10
    exit
```
This configuration intentionally creates a VLAN mismatch for testing purposes.

---

## Verification

### Step 1: Verify VLAN Configuration
```bash
show vlan brief
```
---

### Step 2: Verify Trunk Status
```bash
show interfaces trunk
```
![trunk](images/4.%20Trunk.png)

---

### Step 3: Test Connectivity
```bash
ping 192.168.10.3
```
![ping doesnt work](images/2.%20Ping_no_work.png)

---

### Step 4: Troubleshooting VLAN Mismatch
1. Identify VLAN Mismatch:
```bash
show spanning-tree
```
![spanning tree](images/5.%20spanning%20tree.png)

2. Correct the Native VLAN:
```bash
interface fastethernet 0/24
switchport trunk native vlan 70
exit
```
3. Verify Resolution:
```bash
ping 192.168.10.3
```
![ping works](images/3.%20Ping_work.png)