# **Task: Capturing and Explaining the DHCP DORA Process Using Wireshark (done in VirtualBox Ubuntu)**

## **Objective**
1. Capture DHCP Discover, Offer, Request, and Acknowledge (DORA) messages using Wireshark.
2. Explain the DHCP process step-by-step, integrating captured packet data.
3. Include a DHCP release command to demonstrate how the client initiates the DORA process.

---

## **1. Introduction to DHCP and DORA Process**
The Dynamic Host Configuration Protocol (DHCP) automates the assignment of IP addresses and other network configurations to devices in a network. The DORA process—**Discover, Offer, Request, and Acknowledge**—is the sequence of messages exchanged between the client and the server to allocate an IP address.

### **DORA Process Overview**
1. **Discover**: The client broadcasts a request to locate a DHCP server.
2. **Offer**: The server responds with an available IP address and configuration.
3. **Request**: The client requests the offered IP address.
4. **Acknowledge**: The server confirms the allocation of the IP address.

---

## **2. Capturing Packets in Wireshark**

### **Steps to Capture DHCP Packets**
1. **Launch Wireshark**:
   - Open Wireshark on the client device.

2. **Select the Network Interface**:
   - Choose the interface connected to the network (e.g., Ethernet or Wi-Fi).

3. **Start Capturing**:
   - Click the "Start" button to begin capturing traffic.

4. **Apply a DHCP Filter**:
   - Use the filter `bootp` to isolate DHCP packets in Wireshark.

5. **Trigger the DHCP Process**:
   - Release the current IP and request a new one using the command:
     ```bash
     sudo dhclient -r
     sudo dhclient
     ```

6. **Stop Capturing**:
   - Once the DHCP process completes, click the "Stop" button in Wireshark.

---

## **3. Analysis of Captured Packets (DORA Process)**

Below is the analysis of the four DHCP messages captured in Wireshark. Refer to the images provided to illustrate each step:

### **DHCP Discover**
- **Description**:
  The client broadcasts a DHCP Discover message to find an available server.
- **Packet Details**:
  - **Source IP**: `0.0.0.0`
  - **Destination IP**: `255.255.255.255` (broadcast)
  - **Purpose**: Locate any available DHCP servers.
  - **Screenshot**: ![DHCP Discover](images/3.%20discover.png)

---

### **DHCP Offer**
- **Description**:
  The server replies with a DHCP Offer message containing an available IP address.
- **Packet Details**:
  - **Source IP**: DHCP Server IP (`10.0.2.2`)
  - **Destination IP**: `255.255.255.255` (broadcast)
  - **Purpose**: Offer an IP address to the client.
  - **Screenshot**: ![DHCP Offer](images/4.%20offer.png)

---

### **DHCP Request**
- **Description**:
  The client sends a DHCP Request message to accept the offered IP address.
- **Packet Details**:
  - **Source IP**: `0.0.0.0`
  - **Destination IP**: `255.255.255.255` (broadcast)
  - **Purpose**: Request the offered IP address from the server.
  - **Screenshot**: ![DHCP Request](images/5.%20request.png)

---

### **DHCP Acknowledge**
- **Description**:
  The server responds with a DHCP Acknowledge message to finalize the IP assignment.
- **Packet Details**:
  - **Source IP**: DHCP Server IP (`10.0.2.2`)
  - **Destination IP**: `255.255.255.255` (broadcast)
  - **Purpose**: Confirm and assign the IP address to the client.
  - **Screenshot**: ![DHCP Acknowledge](images/6.%20ack.png)

---

### **Ping**
![Ping](images/1.%20Command.png)

