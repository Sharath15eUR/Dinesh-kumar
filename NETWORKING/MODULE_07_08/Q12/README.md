# Standard Access Control List Implementation in Cisco Packet Tracer

## Objective
To configure a standard access control list (ACL) on a router to permit traffic from a specific IP range and test connectivity to verify that the ACL is working as intended.

---

## Network Topology

### **Devices Required**
- **1 Router**: To configure the ACL.
- **1 Switch**: To connect end devices.
- **4 PCs**: To simulate legitimate and unauthorized traffic.

![Setup](images/1.%20Setup.png)

---

## IP Addressing

| Device  | Interface          | IP Address       | Subnet Mask      |
|---------|-------------------|------------------|-----------------|
| Router  | FastEthernet 0/0  | 192.168.1.1      | 255.255.255.0   |
| PC1     | Ethernet          | 192.168.1.2      | 255.255.255.0   |
| PC2     | Ethernet          | 192.168.1.3      | 255.255.255.0   |
| PC3     | Ethernet          | 192.168.1.4      | 255.255.255.0   |
| PC4     | Ethernet          | 192.168.1.5      | 255.255.255.0   |

**Permitted IP Range:** 192.168.1.2 to 192.168.1.3 (**PC1** and **PC2**).

---

## Configuration Steps

### **1. Configure the Router**

Access the router's CLI:

```bash
Router> enable
Router# configure terminal
```

Configure the **FastEthernet 0/0** interface:

```bash
Router(config)# interface fastEthernet 0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# no shutdown
Router(config-if)# exit
```

Define the **standard ACL**:

```bash
Router(config)# access-list 1 permit 192.168.1.2
Router(config)# access-list 1 permit 192.168.1.3
Router(config)# access-list 1 deny any
```

Apply the ACL to the **FastEthernet 0/0** interface:

```bash
Router(config)# interface fastEthernet 0/0
Router(config-if)# ip access-group 1 in
Router(config-if)# exit
```
![Setup](images/2.%20ACL.png)

---

## Verification Steps

### **1. Ping Tests**

#### **Allowed Traffic:**
From **PC1** and **PC2**, ping the router's IP (**192.168.1.1**):

```bash
ping 192.168.1.1
```
![Setup](images/3.%20PC1.png)

**Expected outcome:** Success (as they are within the permitted range).

#### **Blocked Traffic:**
From **PC3** and **PC4**, ping the router's IP (**192.168.1.1**):

```bash
ping 192.168.1.1
```
![Setup](images/4.%20PC3.png)

**Expected outcome:** Failure (as they are outside the permitted range).

### **2. View ACL Logs**
Check the ACL match statistics on the router:

```bash
Router# show access-lists
```
![Setup](images/5.%20access%20list.png)

Confirm packet match counts for permitted and denied rules.

---
