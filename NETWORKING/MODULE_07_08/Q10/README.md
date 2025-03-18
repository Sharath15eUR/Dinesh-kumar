# Inter-VLAN Routing with Router-on-a-Stick

## **Overview**
This guide explains how to set up **Inter-VLAN Routing** using a **Router-on-a-Stick** method in Cisco Packet Tracer. The configuration includes VLAN creation, trunk setup, router configuration, and verification steps.

---

## **Network Topology & Devices**

### **Devices Required**
- **1 Router** (Cisco 2911)
- **1 Switch** (Cisco 2960)
- **3 PCs** (PC-1, PC-2, PC-3)
- **Ethernet cables** (Straight-through)

![Setup](images/1.%20Setup.png)

### **VLAN & IP Configuration**

| VLAN | Name  | IP Subnet          | PC Assigned |
|------|------|--------------------|-------------|
| 10   | Sales  | 192.168.10.0/24  | PC-1        |
| 20   | HR    | 192.168.20.0/24  | PC-2        |
| 30   | IT    | 192.168.30.0/24  | PC-3        |

### **Connections**
1. **Router** → **Switch (Port F0/1)**
2. **Switch** → **PC-1 (F0/2, VLAN 10)**
3. **Switch** → **PC-2 (F0/3, VLAN 20)**
4. **Switch** → **PC-3 (F0/4, VLAN 30)**

---

## **Configuration Steps**

### **1. Configure VLANs on the Switch**
```bash
Switch> enable
Switch# configure terminal
Switch(config)# vlan 10
Switch(config-vlan)# name Sales
Switch(config-vlan)# vlan 20
Switch(config-vlan)# name HR
Switch(config-vlan)# vlan 30
Switch(config-vlan)# name IT
Switch(config-vlan)# exit
```

### **2. Assign Ports to VLANs**
```bash
Switch(config)# interface fastEthernet 0/2
Switch(config-if)# switchport mode access
Switch(config-if)# switchport access vlan 10
Switch(config-if)# exit

Switch(config)# interface fastEthernet 0/3
Switch(config-if)# switchport mode access
Switch(config-if)# switchport access vlan 20
Switch(config-if)# exit

Switch(config)# interface fastEthernet 0/4
Switch(config-if)# switchport mode access
Switch(config-if)# switchport access vlan 30
Switch(config-if)# exit
```

### **3. Configure Trunk between Switch & Router**
```bash
Switch(config)# interface fastEthernet 0/1
Switch(config-if)# switchport mode trunk
Switch(config-if)# exit
```
![Switch config](images/2.%20Switch%20config.png)

### **4. Configure Router (Router-on-a-Stick)**
```bash
Router> enable
Router# configure terminal
Router(config)# interface FastEthernet 0/0
Router(config-if)# no shutdown
Router(config-if)# exit

Router(config)# interface FastEthernet 0/0.10
Router(config-subif)# encapsulation dot1Q 10
Router(config-subif)# ip address 192.168.10.1 255.255.255.0
Router(config-subif)# exit

Router(config)# interface FastEthernet 0/0.20
Router(config-subif)# encapsulation dot1Q 20
Router(config-subif)# ip address 192.168.20.1 255.255.255.0
Router(config-subif)# exit

Router(config)# interface FastEthernet 0/0.30
Router(config-subif)# encapsulation dot1Q 30
Router(config-subif)# ip address 192.168.30.1 255.255.255.0
Router(config-subif)# exit
```
![Router config](images/4.%20Router%20config.png)
---

## **5. Assign IPs to PCs**

| **PC**        | **IP Address**     | **Subnet Mask**    | **Default Gateway**  |
|---------------|--------------------|--------------------|----------------------|
| PC-1 (Sales)  | 192.168.10.2       | 255.255.255.0      | 192.168.10.1         |
| PC-2 (HR)     | 192.168.20.2       | 255.255.255.0      | 192.168.20.1         |
| PC-3 (IT)     | 192.168.30.2       | 255.255.255.0      | 192.168.30.1         |


**Steps:**
- Go to **PC-1 → Desktop → IP Configuration**
  - **IP Address:** `192.168.10.2`
  - **Subnet Mask:** `255.255.255.0`
  - **Default Gateway:** `192.168.10.1`
- Repeat for **PC-2 (192.168.20.2)** and **PC-3 (192.168.30.2)**

---

## **Verification Steps**

### **1. Check VLANs & Trunk on Switch**
```bash
Switch# show vlan brief
```
![vlan brief](images/3.%20vlan%20brief.png)

```bash
Switch# show interfaces trunk
```

### **2. Test Inter-VLAN Communication**
- **From PC-1**, ping **PC-2** → `ping 192.168.20.2`
- **From PC-2**, ping **PC-3** → `ping 192.168.30.2`

![Ping](images/5.%20PIng.png)

- If successful, inter-VLAN routing is working!

---

## **Expected Outcome**
✅ PCs in different VLANs **should communicate** using the **Router-on-a-Stick** setup.

🚀 If pings fail, check **trunk configuration, VLAN assignments, and IP settings**.

