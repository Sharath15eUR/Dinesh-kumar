# CAPWAP: Control and Provisioning of Wireless Access Points

**CAPWAP (Control and Provisioning of Wireless Access Points)** is a standardized protocol defined by the IETF in RFC 5415. It is used to manage and control wireless access points (APs) from a centralized wireless LAN controller (WLC). CAPWAP simplifies network administration by separating the control and data planes between the AP and the controller.

---

## **Key Features of CAPWAP**
1. **Centralized Management**:
   - Enables network administrators to configure and monitor all access points from a single controller.

2. **Control and Data Plane Separation**:
   - The **Control Plane** handles AP configurations, authentication, and management.
   - The **Data Plane** forwards user traffic to its destination.

3. **Security**:
   - CAPWAP uses **DTLS (Datagram Transport Layer Security)** to encrypt the control channel, ensuring secure communication between the AP and the controller.

4. **Flexibility**:
   - Supports both **tunneled mode** (where user traffic is sent to the controller) and **local mode** (where the AP forwards user traffic directly).

---

## **CAPWAP Flow Between AP and Controller**

### **1. Discovery**
   - The AP attempts to locate a CAPWAP-compatible controller.
   - Methods include:
     - **Broadcast/Multicast Discovery**: Sending discovery messages on the network.
     - **DHCP**: Using DHCP Option 43 to discover the controller's IP address.
     - **DNS**: Resolving a predefined domain name to find the controller.

### **2. Authentication and Secure Channel Establishment**
   - Once the AP discovers the controller, they establish a **secure DTLS tunnel** for communication.
   - The controller authenticates the AP to ensure it is authorized to join the network.

### **3. Configuration**
   - The controller sends the configuration parameters (e.g., SSIDs, security settings) to the AP over the control channel.
   - The AP applies these settings to operate as part of the managed network.

### **4. Data Forwarding**
   - User traffic is handled based on the deployment mode:
     - **Tunneled Mode**: Traffic is encapsulated and forwarded to the controller.
     - **Local Mode**: Traffic is processed and routed directly by the AP.

### **5. Ongoing Management**
   - The controller continuously monitors and manages the AP, including:
     - Firmware updates.
     - Load balancing.
     - Rogue AP detection.
   - The AP communicates periodic status updates to the controller.

---

## **Benefits of CAPWAP**
- Simplifies deployment and scalability for large networks.
- Provides secure and centralized control for improved management.
- Enables dynamic adjustments, such as channel selection and power levels, to optimize network performance.

---

## **Conclusion**
CAPWAP bridges the gap between access points and wireless LAN controllers by streamlining management and ensuring secure communication. By separating the control and data planes, CAPWAP enhances network flexibility, scalability, and performance in modern WLAN environments.

---
