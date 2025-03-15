# **Task: Subnet a Network and Verify Connectivity**

## **Objective**
1. Divide the given network address `10.0.0.0/24` into **4 subnets**.
2. Manually calculate the new subnet mask and the range of valid host IPs for each subnet.
3. Assign IP addresses from these subnets to devices in Packet Tracer.
4. Verify connectivity between devices using ping tests.

---

## **1. Subnetting Details**

### **Given Network Address**
- Network: `10.0.0.0/24`
- Subnet Mask: `255.255.255.0` (default for /24).

### **Subnet Calculation**
To divide the network into **4 subnets**:
- **Step 1**: Increase the subnet mask by **2 bits** (to divide into 4 subnets).
  - New Subnet Mask: `/26` or `255.255.255.192`.
  - Each subnet will have `2^(32-26) = 64` IP addresses (including the network and broadcast addresses).
- **Step 2**: Determine the range of IPs for each subnet.

| **Subnet** | **Network Address** | **Broadcast Address** | **Valid Host Range**        |
|------------|----------------------|------------------------|-----------------------------|
| Subnet 1   | `10.0.0.0`          | `10.0.0.63`           | `10.0.0.1 - 10.0.0.62`      |
| Subnet 2   | `10.0.0.64`         | `10.0.0.127`          | `10.0.0.65 - 10.0.0.126`    |
| Subnet 3   | `10.0.0.128`        | `10.0.0.191`          | `10.0.0.129 - 10.0.0.190`   |
| Subnet 4   | `10.0.0.192`        | `10.0.0.255`          | `10.0.0.193 - 10.0.0.254`   |

---

## **2. Packet Tracer Setup**

### **Network Diagram**
The network is divided into 4 subnets with devices assigned IP addresses as follows:
- **Subnet 1**: PC1 and PC2.
- **Subnet 2**: PC3 and PC4.
- **Subnet 3**: PC5 and PC6.
- **Subnet 4**: PC7 and PC8.

![Network Diagram](images/1.%20Setup.png)
![Static Route Setup](images/2.%20Static%20route%20config.png)

---

### **Device IP Assignments**
| **Device** | **Subnet** | **Assigned IP**        | **Subnet Mask**    |
|------------|------------|------------------------|--------------------|
| PC1        | Subnet 1   | `10.0.0.1`            | `255.255.255.192`  |
| PC2        | Subnet 1   | `10.0.0.2`            | `255.255.255.192`  |
| PC3        | Subnet 2   | `10.0.0.65`           | `255.255.255.192`  |
| PC4        | Subnet 2   | `10.0.0.66`           | `255.255.255.192`  |
| PC5        | Subnet 3   | `10.0.0.129`          | `255.255.255.192`  |
| PC6        | Subnet 3   | `10.0.0.130`          | `255.255.255.192`  |
| PC7        | Subnet 4   | `10.0.0.193`          | `255.255.255.192`  |
| PC8        | Subnet 4   | `10.0.0.194`          | `255.255.255.192`  |

---

## **3. Ping Test Results**

### **Connectivity Verification**
Use `ping` commands to verify communication between devices within and across subnets.

![Ping](images/3.%20Ping.png)
