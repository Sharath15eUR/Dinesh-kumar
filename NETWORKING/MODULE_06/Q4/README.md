# **Task: Identify IP Address Classes, Determine Private/Public, and Explain NAT**

## **Objective**
1. Identify the class of the given IP addresses.
2. Determine whether the IP addresses are **Private** or **Public**.
3. Provide the range of private IP address pools.
4. Explain how NAT (Network Address Translation) handles private IP addresses when accessing the internet.

---

## **1. Given IP Addresses**
- **192.168.10.5**
- **172.20.15.1**
- **8.8.8.8**

---

## **2. Explanation of IP Address Classes**

### **Classes of IP Addresses**
1. **Class A**:
   - **Range**: `1.0.0.0 - 126.255.255.255`.
   - **Default Subnet Mask**: `255.0.0.0`.
   - **Used for**: Very large networks.

2. **Class B**:
   - **Range**: `128.0.0.0 - 191.255.255.255`.
   - **Default Subnet Mask**: `255.255.0.0`.
   - **Used for**: Medium-sized networks.

3. **Class C**:
   - **Range**: `192.0.0.0 - 223.255.255.255`.
   - **Default Subnet Mask**: `255.255.255.0`.
   - **Used for**: Small networks.

---

## **3. Classifications of the Given IP Addresses**

| **IP Address**  | **Class** | **Default Subnet Mask** | **Private/Public** | **Reason**                                |
|------------------|-----------|-------------------------|--------------------|-------------------------------------------|
| `192.168.10.5`   | Class C   | `255.255.255.0`        | Private            | Falls within private range for Class C.   |
| `172.20.15.1`    | Class B   | `255.255.0.0`          | Private            | Falls within private range for Class B.   |
| `8.8.8.8`        | Class A   | `255.0.0.0`            | Public             | Does not fall within any private ranges.  |

---

## **4. Private IP Address Ranges**

Private IP addresses are reserved for internal network communication and are **not routable on the internet**. The private IP pools for each class are:

| **Class** | **Private IP Range**             |
|-----------|----------------------------------|
| Class A   | `10.0.0.0 - 10.255.255.255`     |
| Class B   | `172.16.0.0 - 172.31.255.255`   |
| Class C   | `192.168.0.0 - 192.168.255.255` |

---

## **5. NAT (Network Address Translation) Explanation**

### **How NAT Handles Private IP Addresses**
Private IP addresses cannot be used to access the internet directly because they are not globally unique. NAT allows private IPs to communicate with the internet by translating them into public IP addresses. Here's how it works:

1. **Private to Public Translation**:
   - A private IP (e.g., `192.168.10.5`) is mapped to a public IP assigned by an ISP.
   - The router replaces the private IP address with the public IP in the packet header.

2. **Port Assignment**:
   - NAT assigns a unique port number to track the connection (e.g., `PublicIP:Port`).

3. **Returning Traffic**:
   - When the response is received, NAT maps the public IP and port back to the corresponding private IP.

### **Example**
- **Private IP**: `192.168.10.5` wants to access a website.
- **Translation**:
  - Source IP changes from `192.168.10.5` to a public IP, e.g., `203.0.113.2`.
  - Source Port, e.g., `203.0.113.2:5050`, is assigned to track the connection.
- **Response Handling**:
  - When the web server responds, NAT translates the public IP (`203.0.113.2`) back to the private IP (`192.168.10.5`).


