import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":
    FREQUENCY = 1e3
    # x in seconds
    x = np.arange(0,100)
    sine_at_freq = np.sin(np.pi/4 * x)
    plt.plot(x,sine_at_freq)
    plt.show()
