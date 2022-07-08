# Selezione di Attività
Si basa sul concetto di trovare il maggior numero di attività mutualmente compatibili.

Abbiamo una serie di attività, che iniziano in un tempo $s_i$ e finiscono in un tempo $f_i$.

Un'attività è mutualmente compatibile con un'altra se il tempo di terminazione della precedente è minore o uguale dell'inizio di quella successiva.

| Attività | $\boldsymbol{s_i}$ | $\boldsymbol{f_i}$ |
| :-: | :-: | :-: |
| $P_1$ | $1$ | $4$ |
| $P_2$ | $3$ | $6$ |
| $P_3$ | $1$ | $8$ |
| $P_4$ | $3$ | $5$ |
| $P_5$ | $4$ | $9$ |
| $P_6$ | $5$ | $11$ |
| $P_7$ | $2$ | $9$ |

## Approccio Greedy
L'approccio greedy riesce a trovare una soluzine migliore ordinando le attività per tempi di terminazione crescenti.
<br>La logica dietro è che vogliamo che ogni attività termini il prima possibile, per poter procedere subito con la prossima.

Per prima cosa quindi le ordiniamo per tempi di terminazione crescenti.
| Attività | $\boldsymbol{s_i}$ | $\boldsymbol{f_i}$ |
| :-: | :-: | :-: |
| $P_1$ | $1$ | $4$ |
| $P_4$ | $3$ | $5$ |
| $P_2$ | $3$ | $6$ |
| $P_3$ | $1$ | $8$ |
| $P_5$ | $4$ | $9$ |
| $P_7$ | $2$ | $9$ |
| $P_6$ | $5$ | $11$ |

Selezioniamo subito la prima.
| Attività | $\boldsymbol{s_i}$ | $\boldsymbol{f_i}$ |
| :-: | :-: | :-: |
| $*\boldsymbol{P_1}$ | $\boldsymbol{1}$ | $\boldsymbol{4}$ |
| $P_4$ | $3$ | $5$ |
| $P_2$ | $3$ | $6$ |
| $P_3$ | $1$ | $8$ |
| $P_5$ | $4$ | $9$ |
| $P_7$ | $2$ | $9$ |
| $P_6$ | $5$ | $11$ |

Poi, aggiungiamo la prima attività che parte dopo $f_1 = 4$.
<br>In questo caso $P_5$, con $s_5 = 4$.
| Attività | $\boldsymbol{s_i}$ | $\boldsymbol{f_i}$ |
| :-: | :-: | :-: |
| $*\boldsymbol{P_1}$ | $\boldsymbol{1}$ | $\boldsymbol{4}$ |
| $P_4$ | $3$ | $5$ |
| $P_2$ | $3$ | $6$ |
| $P_3$ | $1$ | $8$ |
| $*\boldsymbol{P_5}$ | $\boldsymbol{4}$ | $\boldsymbol{9}$ |
| $P_7$ | $2$ | $9$ |
| $P_6$ | $5$ | $11$ |

A questo punto procediamo cercando un'attività che parta dopo $f_5 = 9$.
<br>Non ci sono altre attività compatibili, quindi mi fermo.
