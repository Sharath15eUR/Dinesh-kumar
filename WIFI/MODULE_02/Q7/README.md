# Best AP Mode for WLC Deployed in WAN

When a Wireless LAN Controller (WLC) is deployed in a **Wide Area Network (WAN)**, the best Access Point (AP) mode for ensuring local network efficiency is the **FlexConnect Mode** (also referred to as Hybrid Remote Edge Access Point or H-REAP in earlier implementations).

---

## **Why FlexConnect Mode is Best**

FlexConnect allows APs to maintain functionality even when connectivity to the WLC is intermittent or lost, making it ideal for branch offices or remote locations where the WLC is deployed over a WAN link. Here's how it works and why it's advantageous:

---

### **1. Local Switching**
   - In FlexConnect mode, APs can locally switch user traffic without routing it back to the WLC.
   - **Benefits**:
     - Reduces WAN bandwidth usage.
     - Ensures that client data traffic remains within the local network for better performance and lower latency.

---

### **2. Local Authentication**
   - FlexConnect enables APs to authenticate clients using preconfigured credentials or caching mechanisms, even when the WLC is unreachable.
   - **Benefits**:
     - Ensures continued network access during WAN link failures.
     - Improves network reliability in remote locations.

---

### **3. Centralized Management**
   - When WAN connectivity is intact, the APs communicate with the WLC for centralized control, monitoring, and management.
   - **Benefits**:
     - Allows administrators to manage AP configurations and policies from a single, central location.

---

### **4. Failover and Resiliency**
   - If the WAN link to the WLC is disrupted, the AP can:
     - Continue serving existing clients.
     - Process new connections locally.
   - **Benefits**:
     - Ensures uninterrupted network operations for local users.

---

## **Use Case for FlexConnect Mode**
- **Scenario**:
  - A company with a central WLC located at headquarters and branch offices connected via WAN links.
- **Solution**:
  - Deploy APs in FlexConnect mode at the branch offices.
- **Outcome**:
  - Local switching and authentication reduce WAN dependency while maintaining centralized management for consistency.

---

## **Conclusion**

When a WLC is deployed in a WAN environment, **FlexConnect Mode** offers the best balance of local autonomy and centralized management. Its ability to handle local switching and authentication ensures seamless performance for users at remote locations, even during WAN disruptions.

---
