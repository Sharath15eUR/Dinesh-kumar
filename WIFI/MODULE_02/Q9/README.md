# Impact on Wireless Client Connected to Lightweight AP in Local Mode if WLC Goes Down

When a **Wireless LAN Controller (WLC)** goes down, the behavior of a **Lightweight Access Point (AP) operating in local mode** varies depending on the network's configuration. Here’s what typically happens:

---

## **Key Behavior of Lightweight APs in Local Mode**

### **1. Continued Data Forwarding**
   - The lightweight AP continues to handle **local data traffic** as it is configured for **local switching**. 
   - User traffic to and from devices on the same subnet (e.g., within the local network) is unaffected. Internet access may still work if the AP has the necessary configurations and connectivity.

### **2. Limited Authentication Capabilities**
   - For new clients attempting to connect:
     - **Authentication Failures**: If the WLC was managing authentication (e.g., 802.1X with RADIUS), new clients may fail to connect.
     - **Pre-Shared Keys (PSK)**: Clients using PSKs (like WPA/WPA2) may still connect since the AP can handle these locally.

### **3. Loss of Centralized Features**
   - Features managed by the WLC (e.g., dynamic channel assignment, power level adjustments, RF monitoring) cease to function.
   - This may lead to suboptimal performance if the AP cannot adapt autonomously.

### **4. Roaming Challenges**
   - **Client Roaming**:
     - Seamless roaming between APs may be disrupted since the WLC is responsible for managing handoffs between APs.
     - Mobile clients may experience disconnections or delays when moving between APs.

### **5. Management and Monitoring Unavailable**
   - Network administrators lose visibility and control over the affected APs until the WLC is restored.
   - Troubleshooting and configuration changes cannot be made without direct access to the APs.

---

## **Summary**

| **Functionality**          | **Impact**                                  |
|----------------------------|---------------------------------------------|
| **Local Data Forwarding**  | Continues unaffected.                      |
| **New Connections**        | May fail depending on authentication setup. |
| **Centralized Features**   | Cease to function (e.g., channel management). |
| **Client Roaming**         | Seamless roaming disrupted.                |
| **Network Management**     | WLC-dependent monitoring and control lost. |

---

## **Conclusion**

In local mode, lightweight APs can maintain basic data forwarding to ensure uninterrupted connectivity for existing clients. However, new client connections, roaming, and centralized management will be impacted until the WLC is restored. Deploying APs with **FlexConnect mode** can mitigate such issues in WAN environments where WLC outages are possible.

---
