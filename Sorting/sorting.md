# Algoritmi di Ordinamento

| Algoritmo | | | Complessità | Equazione |
| - | - | -: | :- | :- |
| **QuickSort** | Ricorsivo<br>In loco: $\checkmark$<br>Stabile: $✗$ | <br>Peggiore:<br>Migliore:<br>Medio: | <br>$O(n^2)$<br>$O(nlog_2{n})$<br>$O(nlog_2{n})$ | $T(1) = 1$<br>$T(n) = n + T(n - 1)$<br>$T(n) = n + 2T(\frac{n}{2})$<br>$T(n) = n + 2T(\frac{n}{2})$ |
| **MergeSort** | Ricorsivo<br>In loco: $✗$<br>Stabile: $\checkmark$ | | <br>$O(nlog_2{n})$ | $T(1) = 1$<br>$T(n) = n + 2T(\frac{n}{2})$ |
| **HeapSort** | Ricorsivo<br>*(HEAPify)*<br>In loco: $\checkmark$<br>Stabile: $✗$ | | <br>$O(nlog_2{n})$ | $T(1) = 1$<br>$T(n) = log_2{n} + T(n - 1)$|
| **CountingSort** | Iterativo<br>In loco: $✗$<br>Stabile: $\checkmark$ | <br>Migliore:<br>Peggiore: | $O(n + k)$<br>$O(n)$ $k \le n$<br>$O(k)$ $k > n$ | $✗$ *(è iterativo)* |
| **BubbleSort** | Iterativo<br>In loco: $\checkmark$<br>Stabile: $\checkmark$ | | $O(n^2)$ | $T(n) = \sum_{i = 0}^{n}{i}$<br>*(è iterativo)* |
| **SelectionSort** | Iterativo<br>In loco: $\checkmark$<br>Stabile: $✗$ | | $O(n^2)$ | $T(n) = \sum_{i = 0}^{n}{i}$<br>*(è iterativo)* |
| **InsertionSort** | Iterativo<br>In loco: $\checkmark$<br>Stabile: $\checkmark$ | | $O(n^2)$ | $T(n) = \sum_{i = 0}^{n}{i}$<br>*(è iterativo)* |
| **ShellSort** | Iterativo<br>In loco: $\checkmark$<br>Stabile: $✗$ | <br>Knuth: | *dipende*<br>$O(n^\frac{3}{2})$ | |
