# VLAN Trunk Configuration in Cisco Packet Tracer

## Objective
The aim is to set up trunk ports between switches and test connectivity between VLANs in Cisco Packet Tracer. This guide covers the exact connections, device configurations, and verification steps.

---

## Network Setup

### Devices Needed
1. **2 Switches** (e.g., Switch 1 and Switch 2).
2. **4 PCs** (2 PCs for each VLAN: VLAN 10 and VLAN 20).
3. **Connection Medium**: 
   - **Copper straight-through cables**: Connect PCs to switches.
   - **Crossover cable**: Connect Switch 1 to Switch 2.

![Setup](images/1.%20Setup.png)

---

### Network Connections
- **Switch 1**:
  - `FastEthernet 0/1`: Connect to **PC1** (VLAN 10).
  - `FastEthernet 0/2`: Connect to **PC2** (VLAN 20).
  - `FastEthernet 0/24`: Connect to Switch 2 (`FastEthernet 0/24`).

- **Switch 2**:
  - `FastEthernet 0/1`: Connect to **PC3** (VLAN 10).
  - `FastEthernet 0/2`: Connect to **PC4** (VLAN 20).
  - `FastEthernet 0/24`: Connect to Switch 1 (`FastEthernet 0/24`).

---

### IP Address Configuration
Each PC is assigned an IP address within its VLAN subnet:
- **PC1 (VLAN 10)**: `192.168.10.2/24` (Gateway: `192.168.10.1`)
- **PC2 (VLAN 20)**: `192.168.20.2/24` (Gateway: `192.168.20.1`)
- **PC3 (VLAN 10)**: `192.168.10.3/24` (Gateway: `192.168.10.1`)
- **PC4 (VLAN 20)**: `192.168.20.3/24` (Gateway: `192.168.20.1`)

---

## Switch Configuration

### Step 1: Create VLANs
1. Access the CLI of each switch.
2. Create VLANs on both switches:
```bash
   enable
   configure terminal
   vlan 10
   name VLAN10
   exit
   vlan 20
   name VLAN20
   exit
```
---

### Step 2: Assign Access Ports
1. On Switch 1, assign ports to VLANs:
```bash
    interface fastethernet 0/1
    switchport mode access
    switchport access vlan 10
    exit
    interface fastethernet 0/2
    switchport mode access
    switchport access vlan 20
    exit
```
2. On Switch 2, assign ports to VLANs:
```bash
    interface fastethernet 0/1
    switchport mode access
    switchport access vlan 10
    exit
    interface fastethernet 0/2
    switchport mode access
    switchport access vlan 20
    exit
```
---

### Step 3: Configure Trunk Ports
1. On Switch 1:
```bash
    interface fastethernet 0/24
    switchport mode trunk
    exit
```
2. On Switch 2:
```bash
    interface fastethernet 0/24
    switchport mode trunk
    exit
```

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
![Switch 0](images/2.%20Switch%200.png)
![Switch 1](images/3.%20Switch%201.png)

---

### Step 3: Test Connectivity

![Ping](images/4.%20Ping.png)
Ping from VLAN 10 to VLAN 10 is success. BUt Fails when done from VLAN 10 to VLAN 20, thus creating two virtual LAN's in a single LAN
![Simulation](images/5.%20Simulation.png)