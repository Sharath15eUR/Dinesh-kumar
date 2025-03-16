# **README: Understanding Static vs Dynamic NAT in Packet Tracer**

## **1. Static NAT vs Dynamic NAT**

### **Static NAT**
- **Description:**
  - Maps a single private IP address to a single public IP address **statically and permanently**.
  - The mapping remains constant regardless of whether traffic flows.

- **Example Configuration:**
  ```plaintext
  ip nat inside source static 192.168.1.1 200.0.0.5

- **Use Case:**
  - Used for devices requiring consistent access, such as servers or printers.
  
- **Advantages:**
  - Provides a fixed public IP address for devices.

- **Disadvantages:**
  - Inefficient when dealing with many devices because it requires a unique public IP for each private IP.

---

### **Dynamic NAT**
- **Description:**
  - Maps a group of private IPs to a pool of public IPs dynamically as needed.
  - Public IPs are assigned temporarily, only when traffic is initiated.

- **Example Configuration:**
  ```plaintext
  ip nat pool NAT_POOL 200.0.0.5 200.0.0.6 netmask 255.255.255.252
  access-list 1 permit 192.168.1.0 0.0.0.255
  ip nat inside source list 1 pool NAT_POOL

- **Use Case:**
  - Ideal for networks with a large number of internal devices but limited public IPs.
  
- **Advantages:**
  - Efficient public IP usage by dynamically assigning them.

- **Disadvantages:**
  - Public IPs in the pool may be exhausted if too many devices attempt to access the internet simultaneously.


---

## **2. Setup**

In the same setup just added a PC, to show when the pool of Public IP got exhausted a new private IP can't transmit data

![Setup](1.%20Setup.png)

---

## **3. Ping**

![Ping](2.%20Ping.png)

---

## **4. Difference in Configuration**

### **Static NAT Configuration**

#### **Router0**
```plaintext
interface FastEthernet0/0
 ip address 192.168.1.254 255.255.255.0
 ip nat inside
 no shutdown

interface FastEthernet0/1
 ip address 200.0.0.1 255.255.255.252
 ip nat outside
 no shutdown

ip nat inside source static 192.168.1.1 200.0.0.5
ip nat inside source static 192.168.1.2 200.0.0.6

ip route 0.0.0.0 0.0.0.0 200.0.0.2
```

### **Dynamic NAT Configuration**

#### **Router0**
```plaintext
interface FastEthernet0/0
 ip address 192.168.1.254 255.255.255.0
 ip nat inside
 no shutdown

interface FastEthernet0/1
 ip address 200.0.0.1 255.255.255.252
 ip nat outside
 no shutdown

! Define NAT Pool
ip nat pool NAT_POOL 200.0.0.5 200.0.0.6 netmask 255.255.255.252

! Define Access Control List (ACL)
access-list 1 permit 192.168.1.0 0.0.0.255

! Bind ACL to NAT Pool
ip nat inside source list 1 pool NAT_POOL

ip route 0.0.0.0 0.0.0.0 200.0.0.2
```
---

## **5. Key Differences**

| **Component**       | **Static NAT Configuration**                         | **Dynamic NAT Configuration**                         |
|---------------------|------------------------------------------------------|-------------------------------------------------------|
| **NAT Mapping**     | Manually mapped with `ip nat inside source static`.  | Dynamically assigned from a pool using `ip nat pool`. |
| **Access Control**  | No ACL is required.                                  | Uses an ACL to define which private IPs are eligible. |
| **Best for**        | Servers or devices needing fixed IPs.                | Large networks with limited public IPs                |



