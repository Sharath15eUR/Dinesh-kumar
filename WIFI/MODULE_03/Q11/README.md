# Types of PPDU and Their Frame Formats Across Wi-Fi Generations

PPDU (PHY Protocol Data Unit) formats evolve across different Wi-Fi generations to support advancements in speed, efficiency, and robustness. Each format is tailored to the specific capabilities and features of the corresponding Wi-Fi standard.

---

## **Types of PPDU**

1. **Legacy PPDU**:
   - Used in earlier standards such as **802.11a/b/g**.
   - Designed for simpler modulation schemes and basic data rates.

2. **HT (High Throughput) PPDU**:
   - Introduced in **802.11n**.
   - Supports MIMO (Multiple Input, Multiple Output) and wider channels for increased throughput.

3. **VHT (Very High Throughput) PPDU**:
   - Introduced in **802.11ac**.
   - Enables higher-order modulation (e.g., 256-QAM) and larger bandwidth (up to 160 MHz).

4. **HE (High Efficiency) PPDU**:
   - Introduced in **802.11ax (Wi-Fi 6)**.
   - Optimized for dense networks, includes OFDMA (Orthogonal Frequency Division Multiple Access), and supports 1024-QAM.

---

## **PPDU Frame Format Across Wi-Fi Generations**

### **1. Legacy PPDU (802.11a/b/g)**
- **Structure**:
  - **Preamble**: Provides synchronization and training for the receiver.
  - **Signal Field**: Contains information about data rate and frame length.
  - **Data Field**: Carries the user data (payload).

- **Characteristics**:
  - Simplistic design optimized for basic modulation schemes like BPSK and QPSK.
  - Used for moderate data rates up to 54 Mbps.

---

### **2. HT PPDU (802.11n)**
- **Structure**:
  - **HT Preamble**: Includes additional training sequences for MIMO support.
  - **HT Signal Field**: Specifies MIMO configurations and coding rates.
  - **HT Data Field**: Supports wider channels (20 MHz and 40 MHz) for higher throughput.

- **Characteristics**:
  - Introduced MIMO and channel bonding.
  - Maximum data rate up to 600 Mbps.

---

### **3. VHT PPDU (802.11ac)**
- **Structure**:
  - **VHT Preamble**: Enhanced training for multi-user MIMO (MU-MIMO).
  - **VHT Signal Field**: Defines configurations for wider bandwidths (up to 160 MHz).
  - **VHT Data Field**: Supports advanced modulation (256-QAM).

- **Characteristics**:
  - Focus on high-bandwidth applications like streaming.
  - Maximum data rate up to 6.9 Gbps.

---

### **4. HE PPDU (802.11ax - Wi-Fi 6)**
- **Structure**:
  - **HE Preamble**: Optimized for dense networks, includes OFDMA support.
  - **HE Signal Field**: Specifies resource unit (RU) allocations for multiple devices.
  - **HE Data Field**: Supports 1024-QAM for ultra-high data rates.

- **Characteristics**:
  - Enables simultaneous communication with multiple devices via OFDMA.
  - Maximum data rate up to 9.6 Gbps.

---

## **Comparison of PPDU Formats**

| **Wi-Fi Standard** | **PPDU Type**  | **Features**                       | **Max Data Rate** |
|---------------------|----------------|-------------------------------------|-------------------|
| **802.11a/b/g**     | Legacy PPDU    | Basic modulation schemes            | Up to 54 Mbps     |
| **802.11n**         | HT PPDU        | MIMO, channel bonding               | Up to 600 Mbps    |
| **802.11ac**        | VHT PPDU       | MU-MIMO, 256-QAM                    | Up to 6.9 Gbps    |
| **802.11ax (Wi-Fi 6)** | HE PPDU     | OFDMA, 1024-QAM, dense networks     | Up to 9.6 Gbps    |

---

## **Conclusion**

PPDU formats evolve to meet the demands of modern Wi-Fi standards, improving speed, efficiency, and support for multi-user environments. Legacy PPDU laid the foundation, while HE PPDU in Wi-Fi 6 represents cutting-edge technology optimized for dense networks and high-bandwidth applications.

---
