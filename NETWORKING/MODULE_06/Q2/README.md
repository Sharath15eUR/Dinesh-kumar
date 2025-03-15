# **Task: Static Routing Configuration***

## **Objective**
1. Create 2 subnets
2. Configure static routes on a router using ip route
3. Verify connectivity using ing and tracert

---

## **1. Setup**
This network consists of:
1. **Two Routers**: Router 0 (R0) and Router 1 (R1).
2. **Connected Subnets**:
   - **Subnet 1**: Connected to Router 0 via `FastEthernet0/0`.
   - **Subnet 2**: Connected to Router 1 via `FastEthernet0/0`.
3. **Router-to-Router Link**:
   - Connects Router 0 and Router 1 using `FastEthernet0/1`.

![Setup](images/1.%20Setup.png)

### **IP Address Assignments**
| **Device**        | **Interface**       | **IP Address**        | **Subnet Mask**        |
|-------------------|---------------------|------------------------|-------------------------|
| **Router 0 (R0)** | FastEthernet0/0     | 192.168.1.126         | 255.255.255.128        |
|                   | FastEthernet0/1     | 192.168.2.1           | 255.255.255.252        |
| **Router 1 (R1)** | FastEthernet0/0     | 192.168.1.254         | 255.255.255.128        |
|                   | FastEthernet0/1     | 192.168.2.2           | 255.255.255.252        |

### **Connections**
1. **Router 0 (R0)**:
   - `FastEthernet0/0` connects to Subnet 1.
   - `FastEthernet0/1` connects to `FastEthernet0/1` of Router 1.
2. **Router 1 (R1)**:
   - `FastEthernet0/0` connects to Subnet 2.
   - `FastEthernet0/1` connects to `FastEthernet0/1` of Router 0.

---

## **2. Router Configurations**

### **Router 0 Configuration**

![Config](images/2.%20Router%200%20config.png)

```bash
enable
configure terminal

interface FastEthernet0/0
ip address 192.168.1.126 255.255.255.128
no shutdown
exit

interface FastEthernet0/1
ip address 192.168.2.1 255.255.255.252
no shutdown
exit

ip route 192.168.1.128 255.255.255.128 192.168.2.2

exit
write memory
```

---

### **Router 1 Configuration**

![Config](images/3.%20Router%201%20config.png)

```bash
enable
configure terminal

interface FastEthernet0/0
ip address 192.168.1.254 255.255.255.128
no shutdown
exit

interface FastEthernet0/1
ip address 192.168.2.2 255.255.255.252
no shutdown
exit

ip route 192.168.1.0 255.255.255.128 192.168.2.1

exit
write memory
```
---

## **3. Verification**

### **Ping**

![Ping](images/4.%20Ping.png)

---

### **Tracert**

![Tracert](images/5.%20Tracert.png)