# Extended Access Control List (ACL) Implementation in Cisco Packet Tracer

## Objective
To create an extended ACL on a router to block specific applications such as HTTP and FTP traffic, and test the ACL by attempting to access the blocked services.

---

## Network Topology

### **Devices Required**
- **1 Router**: For configuring the extended ACL.
- **2 Switches**: To connect devices.
- **4 PCs**: For testing legitimate and blocked traffic.

![Setup](images/1.%20Setup.png)

### **Connections**
1. Connect the **Router** to **Switch 1** via **FastEthernet 0/0**.
2. Connect the **Router** to **Switch 2** via **FastEthernet 0/1**.
3. Connect **PC1** and **PC2** to **Switch 1**.
4. Connect **PC3** and **PC4** to **Switch 2**.
5. Use **copper straight-through cables** for all connections.

---

## IP Address Assignments

| Device | Interface | IP Address | Subnet Mask |
|--------|-----------|------------|-------------|
| Router | FastEthernet 0/0 | 192.168.1.1 | 255.255.255.0 |
| Router | FastEthernet 0/1 | 192.168.2.1 | 255.255.255.0 |
| PC1 | Ethernet | 192.168.1.2 | 255.255.255.0 |
| PC2 | Ethernet | 192.168.1.3 | 255.255.255.0 |
| PC3 | Ethernet | 192.168.2.2 | 255.255.255.0 |
| PC4 | Ethernet | 192.168.2.3 | 255.255.255.0 |

**Default gateways for PCs should match the respective router interface IPs.**

---

## Configuration Steps

### **Step 1: Configure the Router**

Access the router CLI:

```bash
Router> enable
Router# configure terminal
```

Configure the router interfaces:

```bash
Router(config)# interface fastEthernet 0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# no shutdown
Router(config-if)# exit

Router(config)# interface fastEthernet 0/1
Router(config-if)# ip address 192.168.2.1 255.255.255.0
Router(config-if)# no shutdown
Router(config-if)# exit
```

### **Step 2: Create an Extended ACL**

Block HTTP and FTP traffic:

```bash
Router(config)# access-list 101 deny tcp any any eq 80
Router(config)# access-list 101 deny tcp any any eq 21
Router(config)# access-list 101 permit ip any any
```

### **Step 3: Apply the ACL to the Router Interface**

Attach the ACL to **FastEthernet 0/0** in the inbound direction:

```bash
Router(config)# interface fastEthernet 0/0
Router(config-if)# ip access-group 101 in
Router(config-if)# exit
```
![Router config](images/2.%20Router%20config.png)

---

## Verification Steps

### **Step 1: Test Allowed Traffic**

```bash
ping 192.168.2.2
```
**Expected Outcome:** Success (as ICMP traffic is permitted by default).

### **Step 2: Test Blocked HTTP Traffic**

![HTTP](images/3.%20HTTP%20fail.png)

- **Expected Outcome:** Connection fails, as port 80 traffic is blocked by the ACL.

### **Step 3: Test Blocked FTP Traffic**

```bash
ftp 192.168.2.2
```
![FTP](images/4.%20FTP%20fail.png)

**Expected Outcome:** Connection fails, as port 21 traffic is blocked by the ACL.

### **Step 4: View ACL Logs**
On the router, check the ACL hit counts to verify matches:

```bash
Router# show access-lists
```
![access list](images/5.%20access%20list.png)

**Expected Outcome:** Packet matches will be displayed for the HTTP and FTP deny rules.

---
