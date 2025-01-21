import ctypes
import numpy as np
import matplotlib.pyplot as plt

# Load the shared library
dice_simulation = ctypes.CDLL('./c1.so')

# Define the function prototype
dice_simulation.get_cdf.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_double)]

# Parameters
trials = 100000
output_probs = (ctypes.c_double * 7)()  # For 1, 2, 3, 4, 5, 6, and >3

# Call the C function
dice_simulation.get_cdf(trials, output_probs)

# Convert probabilities to a Python list
probs = list(output_probs)

# Define outcomes: 1, 2, 3, 4, 5, 6, and >3
x_labels = ['1', '2', '3', '4', '5', '6', '>3']

# Plot the probabilities
x = np.arange(len(x_labels))
plt.stem(x, probs, basefmt=" ", use_line_collection=True)
plt.xticks(x, x_labels)
plt.xlabel("Outcomes")
plt.ylabel("Probability")
plt.title("Probability of Dice Outcomes (1, 2, 3, 4, 5, 6, and >3)")
plt.grid()
plt.savefig("../figs/Figure_1.png")
plt.show()

