import matplotlib.pyplot as plt

raw = [float(x) for x in open('raw_values.csv')][:200]
filtered = [float(x) for x in open('filtered_values.csv')][:200]

rawSine = [float(x) for x in open('rawsine_values.csv')][:200]
filteredSine = [float(x) for x in open('filteredsine_values.csv')][:200]

plt.figure(figsize=(12, 6))
plt.plot(raw, label='RAW', alpha=0.7)
plt.plot(filtered, label='FILTERED', alpha=0.7)
plt.title('RC Circuit Signal - RAW vs FILTERED')
plt.xlabel('Sample')
plt.ylabel('ADC Value')
plt.legend()
plt.grid(True)
plt.savefig('docs/rc_plot.png')
plt.show()

plt.figure(figsize=(12, 6))
plt.plot(rawSine, label='RAW SINE WAVE', alpha=0.7)
plt.plot(filteredSine, label='FILTERED SINE WAVE', alpha=0.7)
plt.title('Generated Sine Wave Signal - RAW vs FILTERED')
plt.xlabel('Sample')
plt.ylabel('Sine Value')
plt.legend()
plt.grid(True)
plt.savefig('docs/sine_plot.png')
plt.show()
