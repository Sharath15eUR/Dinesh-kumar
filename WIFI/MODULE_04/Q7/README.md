# Power Saving Scheme in MAC Layer (IEEE 802.11)

Power saving in the MAC layer helps wireless stations (STAs) conserve battery by intelligently switching between active and low-power states. This is critical for mobile and IoT devices.

---

## **MAC Power Saving Basics

- STAs notify the AP when they enter **Power Save Mode (PSM)**.
- AP buffers frames for sleeping STAs.
- Beacon frames carry **Traffic Indication Map (TIM)** to inform STAs of pending data.
- STAs periodically wake up, check the beacon, and decide whether to retrieve data.

---

## **Power Saving Mechanisms**

### 1. **Legacy Power Save Mode (802.11 Standard)**

| Feature       | Description |
|---------------|-------------|
| **Beacon TIM**| AP includes a bitmap (TIM) in beacons showing which STAs have buffered data. |
| **PS-Poll**   | STA sends PS-Poll frame to retrieve buffered frame when indicated. |
| **Sleep Cycle**| STA sleeps between beacons to save power. |

**Pros**: Simple, effective for low-throughput devices.  
**Cons**: Latency in data access, inefficient for bursty traffic.

---

### 2. **Automatic Power Save Delivery (APSD - 802.11e)**

| Type        | Description |
|-------------|-------------|
| **U-APSD**  | STA triggers data delivery using uplink traffic (Unscheduled). |
| **S-APSD**  | STA negotiates fixed intervals for data delivery (Scheduled). |

**Benefits**:
- Lower latency than legacy PSM.
- Better for voice/video traffic.
- Used in QoS (WMM) environments.

---

### 3. **Target Wake Time (TWT - 802.11ax/HE)**

| Feature      | Description |
|--------------|-------------|
| **TWT Agreement** | AP and STA agree on specific wake times. |
| **Fine-grained scheduling** | STA sleeps for longer and wakes up exactly when needed. |

**Use Case**: IoT and high-efficiency networks.

**Pros**: Drastic power savings, low contention.  
**Cons**: Requires negotiation overhead.

---

## **Conclusion**

| Mechanism     | Latency | Efficiency | Use Case           |
|---------------|---------|------------|--------------------|
| Legacy PSM    | High    | Moderate   | General low-duty devices |
| APSD          | Medium  | Better     | QoS apps like VoIP |
| TWT (802.11ax)| Low     | High       | IoT, modern WLANs  |

---

