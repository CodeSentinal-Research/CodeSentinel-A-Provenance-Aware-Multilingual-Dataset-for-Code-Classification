const bst = {
  slug: 'bst',
  phaseId: '09',
  eyebrow: 'Phase 9 — Trees (Part 3)',
  title: 'Binary Search Tree (BST)',
  lede: 'Leveraging the BST invariant (left subtree < node < right subtree) for O(log n) search, insertion, deletion, and global range validation.',

  overview: [
    { label: 'Time Complexity', value: 'O(h) log n avg / O(n) skewed worst-case' },
    { label: 'Space Complexity', value: 'O(h) recursion stack / O(1) iterative' },
    { label: 'Prerequisites', value: 'TreeNode structure, Inorder Traversal, Binary Search (Phase 3)' },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        {
          type: 'p',
          text: 'A Binary Search Tree (BST) is a binary tree defined by an invariant: for every node, every value in its left subtree is smaller, and every value in its right subtree is larger.'
        }
      ]
    },
    {
      num: '02',
      title: 'Why Do We Use It?',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Problem it solves:** Plain sorted arrays offer $O(\log n)$ search but $O(n)$ insertion/deletion due to element shifting.',
            '**Why it was invented:** Encodes halving decisions structurally so insertion and deletion require only pointer rewrites ($O(\log n)$ on balanced trees).',
            '**Inorder Property:** Inorder traversal of a BST produces values in strictly sorted ascending order.'
          ]
        }
      ]
    },
    {
      num: '03',
      title: 'When Should I Think About Using It?',
      blocks: [
        {
          type: 'p',
          text: 'Common interview trigger phrases:'
        },
        {
          type: 'ul',
          items: [
            '"binary search tree" / "validate BST"',
            '"insert / delete node in a BST"',
            '"kth smallest element in a BST"',
            '"lowest common ancestor in a BST"',
            '"range sum query on a BST"'
          ]
        }
      ]
    },
    {
      num: '04',
      title: 'How Does It Work?',
      blocks: [
        {
          type: 'ol',
          items: [
            '**Search / Insert:** Compare target with current node — descend left if target is smaller, right if larger.',
            '**Delete:** 0 children (remove node), 1 child (replace with child), 2 children (copy inorder successor value, recursively delete successor from right subtree).'
          ]
        }
      ]
    },
    {
      num: '05',
      title: 'Dry Run',
      blocks: [
        {
          type: 'p',
          text: '**Problem Tree:**'
        },
        {
          type: 'ascii',
          content: `        8
       / \\
      3   10
     / \\    \\
    1   6    14
       / \\   /
      4   7 13`
        },
        {
          type: 'p',
          text: '**Search Execution (target = 6):**'
        },
        {
          type: 'table',
          headers: ['Step', 'Compare Target vs Node', 'Direction Taken'],
          rows: [
            ['1', '6 vs 8', '6 < 8 → Go Left'],
            ['2', '6 vs 3', '6 > 3 → Go Right'],
            ['3', '6 vs 6', '6 == 6 → MATCH FOUND']
          ]
        },
        {
          type: 'p',
          text: '**Insert Execution (val = 5):**'
        },
        {
          type: 'table',
          headers: ['Step', 'Compare Val vs Node', 'Action'],
          rows: [
            ['1', '5 vs 8', '5 < 8 → Go Left'],
            ['2', '5 vs 3', '5 > 3 → Go Right'],
            ['3', '5 vs 6', '5 < 6 → Go Left'],
            ['4', '5 vs 4', '5 > 4 → Go Right (4.right is null → Insert 5 as 4.right)']
          ]
        }
      ]
    },
    {
      num: '06',
      title: 'Visual Element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `        8
       / \\
      3   10
     / \\    \\
    1   6    14
       / \\   /
      4   7 13
       \\
        5   ← newly inserted

Search path for 6:  8 → 3 → 6
Insert path for 5:  8 → 3 → 6 → 4 → 5`
        }
      ]
    },
    {
      num: '07',
      title: 'Time Complexity',
      blocks: [
        {
          type: 'p',
          text: '**O(h)** — $O(\log n)$ average on balanced trees; $O(n)$ worst case on skewed trees.'
        }
      ]
    },
    {
      num: '08',
      title: 'Space Complexity',
      blocks: [
        {
          type: 'p',
          text: '**O(h)** call stack for recursive versions; **O(1)** for iterative implementations.'
        }
      ]
    },
    {
      num: '09',
      title: 'Cost Analysis',
      blocks: [
        {
          type: 'p',
          text: 'One comparison per level of descent. Operations scale directly with tree height $h$.'
        }
      ]
    },
    {
      num: '10',
      title: 'The Catch ⭐',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Unbalanced Tree Degradation:** Inserting sorted data yields a single long branch ($O(n)$ time).',
            '**Naive Local Validation Trap:** Checking only `node.left.val < node.val < node.right.val` misses ancestor violations! Must thread `(min, max)` range limits.',
            '**Two-Children Deletion:** Copy successor value, then recursively delete successor from right subtree. Successor is guaranteed to have $\\le 1$ child.'
          ]
        }
      ]
    },
    {
      num: '11',
      title: 'Prerequisites',
      blocks: [
        {
          type: 'p',
          text: 'TreeNode structure, Inorder Traversal (Phase 9 Part 1), Binary Search (Phase 3).'
        }
      ]
    },
    {
      num: '12',
      title: 'Variations',
      blocks: [
        {
          type: 'collapse',
          title: 'i) Search & Insert in BST',
          tag: 'O(h) Time | O(h) Space',
          defaultOpen: true,
          blocks: [
            {
              type: 'p',
              text: 'Navigates left or right based on target comparison.'
            },
            {
              type: 'code',
              language: 'java',
              label: 'Search & Insert (Java)',
              code: {
                java: `public boolean search(TreeNode root, int target) {
    if (root == null) return false;
    if (root.val == target) return true;
    return target < root.val ? search(root.left, target) : search(root.right, target);
}

public TreeNode insert(TreeNode root, int val) {
    if (root == null) return new TreeNode(val); // insert slot found
    if (val < root.val) root.left = insert(root.left, val);
    else if (val > root.val) root.right = insert(root.right, val);
    return root;
}`,
                javascript: `function search(root, target) {
    if (root == null) return false;
    if (root.val == target) return true;
    return target < root.val ? search(root.left, target) : search(root.right, target);
}

function insert(root, val) {
    if (root == null) return new TreeNode(val); // insert slot found
    if (val < root.val) root.left = insert(root.left, val);
    else if (val > root.val) root.right = insert(root.right, val);
    return root;
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'ii) Delete Node in a BST',
          tag: 'O(h) Time | O(h) Space | Inorder Successor',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'Handles 0, 1, or 2 children. Two-children case copies inorder successor (leftmost node in right subtree) and recursively deletes successor.'
            },
            {
              type: 'code',
              language: 'java',
              label: 'Delete Node (Java)',
              code: {
                java: `public TreeNode deleteNode(TreeNode root, int key) {
    if (root == null) return null;

    if (key < root.val) {
        root.left = deleteNode(root.left, key);
    } else if (key > root.val) {
        root.right = deleteNode(root.right, key);
    } else {
        // Node found
        if (root.left == null) return root.right; // 0 or 1 child (right)
        if (root.right == null) return root.left;  // 1 child (left)

        // 2 children: find inorder successor (leftmost in right subtree)
        TreeNode successor = root.right;
        while (successor.left != null) successor = successor.left;

        root.val = successor.val; // copy successor value
        root.right = deleteNode(root.right, successor.val); // delete successor
    }
    return root;
}`,
                javascript: `function deleteNode(root, key) {
    if (root == null) return null;

    if (key < root.val) {
        root.left = deleteNode(root.left, key);
    }function if(root.val) {
        root.right = deleteNode(root.right, key);
    } else {
        // Node found
        if (root.left == null) return root.right; // 0 or 1 child (right)
        if (root.right == null) return root.left;  // 1 child (left)

        // 2 children: find inorder successor (leftmost in right subtree)
        TreeNode successor = root.right;
        while (successor.left != null) successor = successor.left;

        root.val = successor.val; // copy successor value
        root.right = deleteNode(root.right, successor.val); // delete successor
    }
    return root;
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'iii) Validate Binary Search Tree',
          tag: 'O(n) Time | O(h) Space | Global Min/Max Bounds',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'Validates BST globally by passing `(min, max)` range limits downward during recursion.'
            },
            {
              type: 'p',
              text: '**Trap Dry Run (Why Local Check Fails):**'
            },
            {
              type: 'ascii',
              content: `        10
        / \\
       5   15
           / \\
          6   20`
            },
            {
              type: 'p',
              text: 'Local check sees `15 > 6` and `15 < 20` as valid. Global range check threads range `(10, 15)` to node `6`. Since $6 \le 10$, validation fails!'
            },
            {
              type: 'code',
              language: 'java',
              label: 'Validate BST (Java)',
              code: {
                java: `public boolean isValidBST(TreeNode root) {
    return validate(root, null, null);
}

private boolean validate(TreeNode node, Integer min, Integer max) {
    if (node == null) return true;
    if ((min != null && node.val <= min) || (max != null && node.val >= max)) {
        return false; // violates inherited ancestor bound
    }
    return validate(node.left, min, node.val)   // narrow upper bound going left
        && validate(node.right, node.val, max); // narrow lower bound going right
}`,
                javascript: `function isValidBST(root) {
    return validate(root, null, null);
}

function validate(node, min, max) {
    if (node == null) return true;
    if ((min != null && node.val <= min) || (max != null && node.val >= max)) {
        return false; // violates inherited ancestor bound
    }
    return validate(node.left, min, node.val)   // narrow upper bound going left
        && validate(node.right, node.val, max); // narrow lower bound going right
}`
              }
            }
          ]
        }
      ]
    },
    {
      num: '13',
      title: 'Related Patterns',
      blocks: [
        {
          type: 'chain',
          nodes: [
            { label: 'BST', desc: 'you are here', current: true },
            { label: 'Inorder Traversal', desc: 'yields sorted sequence' },
            { label: 'Binary Search (Phase 3)', desc: 'same halving concept in tree form' },
            { label: 'Segment Tree (Phase 16)', desc: 'specialized range query tree structure' }
          ],
          arrows: [
            'uses property of',
            'adapts from',
            'extends to'
          ]
        }
      ]
    },
    {
      num: '17',
      title: 'Intuition',
      blocks: [
        {
          type: 'p',
          text: 'A BST encodes past binary search halving choices as tree left/right branches, enabling dynamic $O(\log n)$ search, insert, and delete.'
        }
      ]
    },
    {
      num: '18',
      title: 'Pseudocode',
      blocks: [
        {
          type: 'code',
          language: 'plaintext',
          label: 'BST Search & Validate Pseudocode',
          code: `// BST Search
function search(node, target):
    if node == null: return false
    if node.val == target: return true
    if target < node.val: return search(node.left, target)
    else: return search(node.right, target)

// Validate BST
function validate(node, min, max):
    if node == null: return true
    if (min != null and node.val <= min) or (max != null and node.val >= max):
        return false
    return validate(node.left, min, node.val) and validate(node.right, node.val, max)`
        }
      ]
    },
    {
      num: '19',
      title: 'Code Template',
      blocks: [
        {
          type: 'code',
          language: 'java',
              label: 'BST Operations Shell (Java)',
              code: {
                java: `public TreeNode bstTemplate(TreeNode root, int target) {
    if (root == null || root.val == target) return root;
    if (target < root.val) return bstTemplate(root.left, target);
    return bstTemplate(root.right, target);
}`,
                javascript: `function bstTemplate(root, target) {
    if (root == null || root.val == target) return root;
    if (target < root.val) return bstTemplate(root.left, target);
    return bstTemplate(root.right, target);
}`
              }
        }
      ]
    },
    {
      num: '20',
      title: 'Interview Checklist',
      blocks: [
        {
          type: 'checklist',
          id: 'bst-checklist',
          items: [
            'Am I taking advantage of BST ordering to achieve $O(h)$ navigation?',
            'In Validate BST: am I threading `(min, max)` range limits downward rather than checking local parent-child pairs?',
            'In Delete Node: am I recursively deleting the successor from its original position after copying its value?',
            'Is duplicate value handling explicit and consistent across operations?'
          ]
        }
      ]
    }
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: 'A Binary Search Tree preserves an ordering invariant that unlocks simultaneous O(log n) search, insertion, and deletion on balanced trees.'
  }
};

export default bst;
