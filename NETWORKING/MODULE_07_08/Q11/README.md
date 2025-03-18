# ACL Implementation

## Objective
To configure a standard access control list (ACL) on a router to permit traffic from a specific source and destination ports and test connectivity to verify that the ACL is working as intended.

---

## Network Topology 

### Devices Required:

- **1 Router**: To implement and apply ACLs.
- **2 Switches**: To connect end devices.
- **4 PCs**: To test legitimate and unauthorized traffic.

![Setup](images/1.%20Setup.png)

### Connections:

1. Connect the **Router** to **Switch 1** via **FastEthernet 0/0**.
2. Connect the **Router** to **Switch 2** via **FastEthernet 0/1**.
3. Connect **PC1** and **PC2** to **Switch 1**.
4. Connect **PC3** and **PC4** to **Switch 2**.
5. Use **copper straight-through cables** for all connections.

### IP Address Assignments:

| Device | Interface        | IP Address     |
|--------|------------------|----------------|
| Router | FastEthernet 0/0 | 192.168.1.1/24 |
| Router | FastEthernet 0/1 | 192.168.2.1/24 |
| PC1    | Switch - fa0/2   | 192.168.1.2/24 |
| PC2    | Switch - fa0/3   | 192.168.1.3/24 |
| PC3    | Switch - fa0/2   | 192.168.2.2/24 |
| PC4    | Switch - fa0/3   | 192.168.2.3/24 |

**Default gateways for PCs should match the respective router interface IPs.**

---

## Configuration Steps

### **Router Configuration**

1. Access the router CLI and configure IP addresses for both FastEthernet interfaces:

```bash
Router> enable
Router# configure terminal
Router(config)# interface fastEthernet 0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# no shutdown
Router(config-if)# exit
Router(config)# interface fastEthernet 0/1
Router(config-if)# ip address 192.168.2.1 255.255.255.0
Router(config-if)# no shutdown
Router(config-if)# exit
```

### **Define ACL Rules**

Create an extended ACL to permit and deny specific traffic:

```bash
Router(config)# access-list 100 permit tcp 192.168.1.0 0.0.0.255 any eq 80
Router(config)# access-list 100 deny tcp 192.168.1.0 0.0.0.255 any eq 23
Router(config)# access-list 100 permit ip any any
```

### **Apply ACL to Interfaces**

Bind the ACL to the router’s FastEthernet 0/0 interface for incoming traffic:

```bash
Router(config)# interface fastEthernet 0/0
Router(config-if)# ip access-group 100 in
Router(config-if)# exit
```
![ACL](images/2.%20ACL%20rules.png)

---

## Verification Steps

### **Ping Test for Basic Connectivity:**

From PC1, use the `ping` command to test connectivity to PC3:

```bash
ping 192.168.2.2
```
![ping](images/3.%20ping.png)

**Expected outcome:** Ping should succeed, as ICMP traffic is not restricted by the ACL.

### **Test Legitimate Traffic (Port 80):**

From PC1, try to connect to PC3:

```bash
telnet 192.168.2.2 80
```
![ACL](images/4.%2080%20allowed.png)

**Expected outcome:** Connection should succeed since port 80 is allowed by the ACL.

**Observation:** The router is allowing traffic to reach the destination (PC3), but there’s no service listening on port 80 on PC3 to accept the connection.The packet is delivered, but PC3 is rejecting it because it doesn't have a web service running on port 80.

### **Test Unauthorized Traffic (Port 23):**

From PC1, try to connect to PC3:

```bash
telnet 192.168.2.2 23
```
![ACL](images/5.%2023%20not%20allowed.png)

**Expected outcome:** Connection should fail since port 23 is denied by the ACL.

**Observation:** This occurs because the ACL rule on the router is blocking Telnet traffic (port 23), so the packets never reach PC3. The timeout happens as the source host (PC1) waits for a response that never arrives.

### **Check ACL Logs:**

Use the following command on the router to verify hit counts for ACL rules:

```bash
Router# show access-lists
```
![access-lists](images/6.%20Show.png)

---

