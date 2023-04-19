import seaborn as sns
import matplotlib.pyplot as plt

lista = [0.040896, 0.042114 ,0.051476, 0.044331, 0.074126, 0.076928, 0.077393, 0.077326]
thered = ['1','2','3','4','5','6','7','8']

sns.lineplot(x=thered, y=lista)
plt.xlabel('THREADS')
plt.ylabel('Tempo de execução')
plt.show()
