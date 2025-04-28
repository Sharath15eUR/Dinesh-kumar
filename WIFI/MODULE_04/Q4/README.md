# Scanning Process in IEEE 802.11

**Scanning** is the process through which a wireless station (STA) searches for available access points (APs) to initiate association. It ensures mobility, roaming, and connectivity in dynamic wireless environments.

---

## **Purpose of Scanning**

- Discover available networks
- Identify optimal AP (based on signal strength, load, etc.)
- Initiate connection via authentication and association

---

## **Types of Scanning**

### 1. **Passive Scanning**

| Feature            | Description |
|--------------------|-------------|
| **Mechanism**      | STA listens for **beacon frames** broadcast periodically by APs. |
| **Operation**      | No transmission from STA. Just listens on each channel for a specific time. |
| **Pros**           | Power-efficient, stealth (no active probe sent). |
| **Cons**           | Slower (depends on beacon interval), may miss hidden APs. |

### Steps:
1. STA tunes to a channel.
2. Waits for a beacon frame.
3. Moves to the next channel if none is received.

---

### 2. **Active Scanning**

| Feature            | Description |
|--------------------|-------------|
| **Mechanism**      | STA sends **probe request** frames on each channel and waits for **probe responses**. |
| **Operation**      | Explicit transmission from STA to discover nearby APs. |
| **Pros**           | Faster discovery, detects hidden APs. |
| **Cons**           | More power consumption, more channel usage. |

### Steps:
1. STA broadcasts a probe request on a channel.
2. Nearby APs respond with probe response frames.
3. STA evaluates responses and selects an AP.

---

## **Usage**

| Scenario                         | Preferred Scanning |
|----------------------------------|---------------------|
| Battery-constrained devices      | Passive             |
| Fast roaming and quick connect   | Active              |
| Presence of hidden APs           | Active              |
| High-interference environments   | Passive (less noise) |

---

## **Conclusion**

- **Passive Scanning**: STA listens → low power, slow.
- **Active Scanning**: STA probes → faster, more visible.
- Scanning is critical for **network discovery**, **roaming**, and **load balancing** in wireless networks.

---

