# TASK I — Рефлексия

### 1. Какие функции войдут в публичный интерфейс множества, а какие останутся деталями реализации? Правда ли они могут иметь другое название?

**Публичный интерфейс множества:**
- `bstInsert` / `setInsert` — добавление элемента
- `bstContains` / `setContains` — проверка принадлежности элемента
- `bstDelete` / `setDelete` — удаление элемента
- `bstSize` / `setSize` — количество элементов
- `bstFree` / `setFree` — освобождение памяти
- `iteratorInit`, `iteratorHasNext`, `iteratorNext`, `iteratorFree` — итератор для перебора

**Детали реализации (скрыты от пользователя):**
- работа с узлами: `createNode`, `insertNode`, `nodeContains`, `freeNodes`, `findMin`, `deleteNode`
- рекурсивные вспомогательные: `bstHeightRecursive`, `bstSizeRecursive`, `bstKthMinRecursive`
- обходы дерева: `bstInorderRecursive`, `bstPreorderRecursive`, `bstPostorderRecursive`, `bstInorder`, `bstPreorder`, `bstPostorder`
- вспомогательные для слияния: `inorderFillArr`, `mergeSorted`, `buildBalanced`
- валидация: `isNodeValid`, `bstIsValid`
- итератор-детали: `push`, `pop`

**Операции, не входящие в стандартный интерфейс множества:**
- `bstMin`, `bstMax` — это функции BST, а не множества
- `bstKthMin` —  операция для  дерева, не имеет смысла в множестве
- `bstMerge` — может быть включена как `setUnion`

**Да, названия могут быть другими** — вместо  `bst` разумно использовать `set` (setInsert, setContains и т.д.), чтобы скрыть конкретную реализацию.

---

### 2. Какие из написанных вами функций не имеют смысла в интерфейсе множества?

- `bstHeight`, `bstHeightRecursive` — работают со структурой дерева, не множества
- `bstMin`, `bstMax` — детали BST, не множества
- `bstKthMin`, `bstKthMinRecursive` —  операция дерева
- `bstInorder`, `bstPreorder`, `bstPostorder` —  обходы дерева не имеют смысла в интерфейсе множества 
- `bstIsValid`, `isNodeValid` — проверка структуры дерева, не множества
- `push`, `pop` — детали реализации итератора

---

### 3. Что нужно изменить, чтобы можно было безболезненно заменить BST на другую реализацию (например, хеш-таблицу), не меняя код, который использует множество?

1. **Инкапсуляция (opaque pointer):** пользователь не должен видеть структуру `BST`. Пользователь работает только с `Set`.

2. **Публичный интерфейс:** все функции обхода дерева, проверки валидности, работы с узлами напрямую — они должны быть недоступны пользователю.
