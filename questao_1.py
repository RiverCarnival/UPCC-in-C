import seaborn as sns
import matplotlib.pyplot as plt

lista = [0.042303,0.041583,0.042862,0.044456,0.073928,0.076607,0.077133,0.099384]
thered = ['1','2','3','4','5','6','7','8']

sns.lineplot(x=thered, y=lista)
plt.xlabel('THREADS')
plt.ylabel('Tempo de execução')
plt.show()
