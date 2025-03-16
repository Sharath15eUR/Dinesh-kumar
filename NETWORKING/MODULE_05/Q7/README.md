# **Task: NAT Configuration in Packet Tracer**

## **Objective**
1. Configure NAT on Router0 to translate private IPs of connected PCs to public IPs.
2. Connect Router0 to an external server via Router1, simulating internet access.
3. Test NAT configuration by pinging an external IP from the PCs.
4. Capture traffic to observe source IP addresses before and after NAT.

---

## **Network Setup**
### **Devices and Connections**
1. **PC0** and **PC1**: Connected to Router0 (NAT Router).
2. **Router0**: Configured to perform NAT with:
   - Inside Interface: Connected to PCs.
   - Outside Interface: Connected to Router1.
3. **Router1**: Acts as an intermediary router, simulating the internet.
   - Connects Router0 to a simulated Google server (`8.8.8.8`).
4. **Simulated Google Server**: External server (`8.8.8.8`) representing the internet.

![Setup](images/1.%20Setup.png)

### **IP Addressing**

| **Device/Interface**         | **IP Address**        | **Subnet Mask**      | **Purpose**                          |
|-------------------------------|-----------------------|----------------------|--------------------------------------|
| **PC0**                      | `192.168.1.1`        | `255.255.255.0`      | Private IP for NAT                   |
| **PC1**                      | `192.168.1.2`        | `255.255.255.0`      | Private IP for NAT                   |
| **Router0 (Inside, Fa0/0)**  | `192.168.1.254`      | `255.255.255.0`      | Gateway for PCs                      |
| **Router0 (Outside, Fa0/1)** | `200.0.0.1`          | `255.255.255.252`    | Public IP for NAT to Router1         |
| **Router1 (Inside, Fa0/1)**  | `200.0.0.2`          | `255.255.255.252`    | Connected to Router0                 |
| **Router1 (Outside, Fa0/0)** | `8.0.0.1`            | `255.0.0.0`          | Gateway to the simulated internet    |
| **Google Server**            | `8.8.8.8`            | `255.255.255.255`    | External IP accessible via Router1   |

---

## **Router Configurations**

### **Router0**
```plaintext
interface FastEthernet0/0
 ip address 192.168.1.254 255.255.255.0
 ip nat inside
 no shutdown
 exit

interface FastEthernet0/1
 ip address 200.0.0.1 255.255.255.252
 ip nat outside
 no shutdown
 exit

ip nat inside source static 192.168.1.1 200.0.0.5
ip nat inside source static 192.168.1.2 200.0.0.6

ip route 0.0.0.0 0.0.0.0 200.0.0.2
```

![Static route 0](images/2.%20Router%200.png)

### **Router1**
```plaintext
interface FastEthernet0/1
 ip address 200.0.0.2 255.255.255.252
 no shutdown
 exit

interface FastEthernet0/0
 ip address 8.0.0.1 255.0.0.0
 no shutdown
 exit

ip route 192.168.1.0 255.255.255.0 200.0.0.1
ip route 200.0.0.4 255.255.255.252 200.0.0.1
ip route 8.8.8.8 255.255.255.255 FastEthernet0/0
```
![Static route 1](images/3.%20Router%201.png)

---

## **Connectivity Check**

### **Configure IP Addresses:**
1. Assign IPs to all devices/interfaces as per the setup table.
2. Configure NAT on Router0 and set static mappings.

### **Set Static Routes:**
1. On Router0, add a default route pointing to Router1 (200.0.0.2).
2. On Router1, add routes for:
    Private subnet (192.168.1.0/24) via Router0.
    Public NAT IPs (200.0.0.4/30) via Router0.
    Google server (8.8.8.8) via FastEthernet0/0.

### **Test Connectivity:**
1. From PC0 and PC1, ping the Google server (8.8.8.8).
2. Observe successful replies.

(Initially I tried to ping 8.8.8.8, but time reached out since I havent configured the way back (Public IP) from router 1 to 0, which I found out from sending ICMP messages in simulation mode)

### **Capture Traffic in Packet Tracer Simulation Mode:**
1. Observe source IP transformations:
2. Before NAT: Source IP is the private IP (e.g., 192.168.1.1).
3. After NAT: Source IP is translated to public IP (e.g., 200.0.0.5).

### **Verify NAT Translations:**
On Router0, view the NAT table with:

```plaintext
show ip nat translations
```
![NAT table](images/4.%20NAT%20table.png)

(Port numbers could be observed in NAT table, that is used to determine which application data belongs to!)
