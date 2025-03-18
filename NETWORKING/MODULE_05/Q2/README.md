# **Simulating an ARP Spoofing Attack in Cisco Packet Tracer**  

## **1. Network Setup**  
You will create a network consisting of:  
- **1 Switch** (Cisco 2960)  
- **3 PCs** (PC0, PC1, Attacker PC)  
- **Connection Medium:** Copper Straight-Through Cable  

## **2. Device Configuration**  

| **Device**  | **IP Address**  | **MAC Address** (Auto-generated) | **Role**  |
|------------|---------------|--------------------------------|----------|
| **PC0**    | 192.168.1.10  | Auto                          | Victim 1 |
| **PC1**    | 192.168.1.20  | Auto                          | Victim 2 |
| **Attacker PC** | 192.168.1.100 | Auto                          | ARP Spoofer |
| **Switch**  | No IP Assigned | N/A                           | Layer 2 Device |

## **3. Steps to Perform the ARP Spoofing Attack**  

### **Step 1: Configure the IP Addresses**  
- On **PC0**, **PC1**, and **Attacker PC**, assign the static IP addresses from the table above using:  
  ```plaintext
  ipconfig /all
  ```

### **Step 2: Check Initial ARP Table (Before Attack)**  
- On **PC0** and **PC1**, run the command:  
  ```plaintext
  arp -a
  ```
- The ARP table will show the correct mapping of IPs to MAC addresses.

### **Step 3: Launch ARP Spoofing Attack from Attacker PC**  
- Open **Attacker PC's** command prompt and use:  
  ```plaintext
  arp -s 192.168.1.10 <Attacker MAC>
  arp -s 192.168.1.20 <Attacker MAC>
  ```
- This forces **PC0** and **PC1** to believe that the attacker's MAC address is the legitimate one.

`But Packet tracer didn't support this command`

### **Step 4: Verify ARP Poisoning**  
- On **PC0** and **PC1**, check the ARP table again:  
  ```plaintext
  arp -a
  ```
- You will notice that both PCs now have the **attacker's MAC** mapped to their respective IP addresses instead of the actual ones.

### **Step 5: Simulating Network Behavior**  
- **Ping Test:** Try `ping 192.168.1.20` from **PC0**.
- **Packet Sniffing:** Use Packet Tracer's built-in **Packet Capture Tool** to inspect ARP requests/replies.

### **Step 6: Observe the Effects**  
- Communication between PC0 and PC1 will now go through the Attacker PC.
- The attacker can perform **Man-in-the-Middle (MitM)** attacks, intercepting or modifying traffic.

---