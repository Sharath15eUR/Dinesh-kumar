# Implementing Static NAT, Dynamic NAT, and PAT in Cisco Packet Tracer

## Objective
To configure Static NAT, Dynamic NAT, and PAT on a router to translate internal IP addresses and enable communication between internal and external networks.

## Network Topology

### Devices Required
- **1 Router**: To configure NAT.
- **1 Switch**: To connect the internal network.
- **4 PCs**: To simulate internal hosts.
- **1 Server**: To simulate the external host for verification.

![Setup](images/1.%20Setup.png)

## IP Addressing

| Device | Interface | IP Address | Subnet Mask | Purpose |
|--------|----------|------------|-------------|---------|
| Router (FastEthernet 0/0) | 192.168.1.1 | 255.255.255.0 | Internal network gateway |
| Router (FastEthernet 0/1) | 203.0.113.1 | 255.255.255.0 | External/Public IP for NAT |
| PC1 | Ethernet | 192.168.1.2 | 255.255.255.0 | Internal host |
| PC2 | Ethernet | 192.168.1.3 | 255.255.255.0 | Internal host |
| PC3 | Ethernet | 192.168.1.4 | 255.255.255.0 | Internal host |
| PC4 | Ethernet | 192.168.1.5 | 255.255.255.0 | Internal host |
| Server (External) | Ethernet | 203.0.113.2 | 255.255.255.0 | External network to test NAT |

---

## Configuration Steps

### Step 1: Router Interface Configuration
Configure the router interfaces for internal and external networks:
```plaintext
Router> enable
Router# configure terminal
Router(config)# interface fastEthernet 0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# ip nat inside
Router(config-if)# no shutdown
Router(config-if)# exit

Router(config)# interface fastEthernet 0/1
Router(config-if)# ip address 203.0.113.1 255.255.255.0
Router(config-if)# ip nat outside
Router(config-if)# no shutdown
Router(config-if)# exit
```

### Step 2: Static NAT Configuration
Map an internal private IP (e.g., PC1) to a specific public IP:
```plaintext
Router(config)# ip nat inside source static 192.168.1.2 203.0.113.10
```

#### Verification for Static NAT
Ping the Server (203.0.113.2) from PC1:
```plaintext
ping 203.0.113.2
```
Check NAT translations:
```plaintext
Router# show ip nat translations
```
![Static](images/2.%20Static%20NAT.png)

---

### Step 3: Dynamic NAT Configuration
Create a pool of public IPs for dynamic translation:
```plaintext
Router(config)# ip nat pool MY_POOL 203.0.113.20 203.0.113.25 netmask 255.255.255.0
```

Create an access list for internal traffic:
```plaintext
Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255
```

Link the access list to the NAT pool:
```plaintext
Router(config)# ip nat inside source list 1 pool MY_POOL
```

#### Verification for Dynamic NAT
Ping the Server (203.0.113.2) from PC2, PC3, or PC4:
```plaintext
ping 203.0.113.2
```
Check NAT translations:
```plaintext
Router# show ip nat translations
```
![Dynamic](images/3.%20Dynamic%20NAT.png)

---

### Step 4: PAT (Port Address Translation) Configuration
Configure PAT using the external interface:
```plaintext
Router(config)# ip nat inside source list 1 interface fastEthernet 0/1 overload
```

#### Verification for PAT
Ping the Server (203.0.113.2) from all internal PCs (PC1 to PC4) simultaneously.

Verify NAT translations:
```plaintext
Router# show ip nat translations
```
![Setup](images/4.%20PAT.png)

---
