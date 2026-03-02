import matplotlib.pyplot as plt

raw = [float(x) for x in open('raw_values.csv')][:200]
filtered = [float(x) for x in open('filtered_values.csv')][:200]

plt.figure(figsize=(12, 6))
plt.plot(raw, label='RAW', alpha=0.7)
plt.plot(filtered, label='FILTERED', alpha=0.7)
plt.title('RC Circuit Signal - RAW vs FILTERED')
plt.xlabel('Sample')
plt.ylabel('ADC Value')
plt.legend()
plt.grid(True)
plt.savefig('signal_plot.png')
plt.show()
