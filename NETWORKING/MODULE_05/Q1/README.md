# **Task: Capture and Analyze ARP Packets**

## **Objective**
The goal of this task is to capture and analyze ARP packets. This includes:
1. Inspecting ARP request and reply frames.
2. Understanding the role of the sender's IP and MAC address in these packets.

---

## **1. ARP Analysis using Wireshark (Mobile Ping)**

### **Setup**
- **Environment**: Wi-Fi network with a laptop and mobile phone.
- **Source Device**: Laptop (`192.168.31.188`).
- **Target Device**: Mobile Phone (`192.168.31.238`).
- **Tool**: Wireshark with an `arp` filter applied.

---

### **Observation 1: ARP Request**

- **Details**:
  - **Sender MAC**: `a0:59:50:39:af:fd` (Laptop).
  - **Sender IP**: `192.168.31.188`.
  - **Target MAC**: `ff:ff:ff:ff:ff:ff` (Broadcast).
  - **Target IP**: `192.168.31.238`.

- **Analysis**:
  The ARP Request is broadcast to all devices on the network (`ff:ff:ff:ff:ff:ff`) to find the MAC address for the target IP (`192.168.31.238`).

![ARP request](images/ARP%20request.png)

---

### **Observation 2: ARP Reply**

- **Details**:
  - **Sender MAC**: `5a:d2:b9:a0:24:84` (Mobile Phone).
  - **Sender IP**: `192.168.31.238`.
  - **Target MAC**: `a0:59:50:39:af:fd` (Laptop).
  - **Target IP**: `192.168.31.188`.

- **Analysis**:
  The ARP Reply is sent as a unicast to the requesting device (`a0:59:50:39:af:fd`), providing its MAC address (`5a:d2:b9:a0:24:84`).

![ARP reply](images/ARP%20reply.png)

---

### **Ping and ARP Table Behavior**

- **Before Ping**:
  - ARP table does not have an entry for `192.168.31.238`.
- **During Ping**:
  - ARP packets are exchanged to resolve the target's MAC address.
  - The ping is successful with ICMP Echo Replies.
- **After Ping**:
  - ARP table is updated with the resolved MAC address of `192.168.31.238`.

---

## **2. ARP Analysis using Cisco Packet Tracer**

### **Setup (Using switch - Layer 2)**
- **Network Setup**:
  - Two PCs: `192.168.0.1` (PC-A) and `192.168.0.4` (PC-D).
  - A Switch connecting the PCs.

![Setup](images/1.%20Setup.png)

- **Tool**: Cisco Packet Tracer with Simulation Mode enabled to capture ARP exchanges.

---

### **Observation 1: ARP Request**

- **Details**:
  - **Sender MAC**: `000D.FF63.4D9D` (PC-A).
  - **Sender IP**: `192.168.0.1`.
  - **Target MAC**: `00:00:00:00:00:00` (Broadcast).
  - **Target IP**: `192.168.0.4`.

- **Analysis**:
  The ARP Request is broadcast across all connected devices to discover the MAC address for `192.168.0.4`.

![ARP request](images/2.%20ARP%20request.png)

---

### **Observation 2: ARP Reply**

- **Details**:
  - **Sender MAC**: `000B.BE51.1012` (PC-D).
  - **Sender IP**: `192.168.0.4`.
  - **Target MAC**: `000D.FF63.4D9D` (PC-A).
  - **Target IP**: `192.168.0.1`.

- **Analysis**:
  The ARP Reply is sent as a unicast to `192.168.0.1`, providing the MAC address for `192.168.0.4`.

![ARP reply](images/3.%20ARP%20reply.png)

---

### **PC-A ARP Cache**
After the ping, the ARP cache on PC-A contains the following:

**Command**: `arp -a`

**Details**:
- The entry for `192.168.0.4` shows the resolved MAC address (`000B.BE51.1012`).

---

## **3. Conclusion**

### **Role of the Sender’s IP and MAC Address**
- **In ARP Requests**:
  - The sender's MAC address identifies the requesting device.
  - The sender's IP address specifies the source of the request to receive the ARP Reply.
- **In ARP Replies**:
  - The sender's IP and MAC provide the requested mapping to the initiator.

### **Broadcast vs. Unicast in ARP**:
- ARP Requests use broadcast to query all devices on the network.
- ARP Replies use unicast to deliver the resolved MAC address to the requester.

This assignment highlights the importance of ARP in enabling communication at the data link layer by resolving IP addresses to MAC addresses in both Wireshark captures and Packet Tracer simulations.
