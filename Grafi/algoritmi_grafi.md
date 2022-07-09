# Algoritmi dei Grafi

| | Algoritmo | Uso | | Complessità |
|-|-|-|-:|:-|
| Visite | **DFS** | Visita in profondità | *ladj*<br>*madj* | $\theta(\lvert\text{V}\rvert + \lvert\text{E}\rvert)$<br>$\theta(\lvert\text{V}\rvert^2)$ |
|| **BFS** | Visita in ampiezza | *ladj*<br>*madj* | $\theta(\lvert\text{V}\rvert + \lvert\text{E}\rvert)$<br>$\theta(\lvert\text{V}\rvert^2)$ |
| Cammini | **Cammino Semplice** || *ladj*<br>*madj* | $O(\lvert\text{V}\rvert + \lvert\text{E}\rvert)$<br>$O(\lvert\text{V}\rvert^2)$ |
|| **Cammino Lungo $\boldsymbol{d}$** ||| $O(\lvert\text{V}\rvert^2)$ |
|| **Cammino di Hamilton**<br>*Cammino Lungo $V$$-$$1$* ||| $O(\lvert\text{V}\rvert^2)$ |
| Cammini<br>minimi | **Dijkstra** || *ladj*<br>*madj* | $O(\lvert\text{V + E}\rvert \text{ } log\lvert\text{V}\rvert)$<br>$O(\lvert\text{V}\rvert^2 \text{ } log\lvert\text{V}\rvert)$ |
|| **Bellman-Ford** ||| $O(\lvert{V}\rvert \text{ } \lvert{E}\rvert)$ |
