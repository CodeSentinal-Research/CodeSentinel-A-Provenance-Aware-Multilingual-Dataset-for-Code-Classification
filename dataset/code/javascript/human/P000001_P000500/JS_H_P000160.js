class Node{
    constructor(data,left,right){
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

class Pair{
    constructor(node,state){
        this.node = node;
        this.state = state
    }
}

function createTree(){
    let arr = [50,25,12,null,null,37,30,null,null,null,75,62,null,70,null,null,87,null,null]
    let root = new Node(arr[0],null,null)
    let rtp = new Pair(root,1)
    let st = []
    st.push(rtp)

    let idx = 0
    while(st.length>0){
        let top  = st[st.length-1]
        if(top.state ===1){
            idx++
            if(arr[idx]!==null){
                top.node.left = new Node(arr[idx],null,null)
                let lp = new Pair(top.node.left,1)
                st.push(lp)
            }else{
                top.node.left = null
            }
            top.state++
        }else if(top.state===2){
            idx++
            if(arr[idx]!==null){
                top.node.right = new Node(arr[idx],null,null)
                let rp = new Pair(top.node.right,1)
                st.push(rp)
            }else{
                top.node.right = null
            }
            top.state++
        }else{
            st.pop()
        }
    }
    return root
}

function displayTree(root){
    if(root===null) return;
    let left = root.left === null ? ".":root.left.data
    let right = root.right === null ? ".":root.right.data
    console.log(left+"<-->"+root.data+"<-->"+right)
    

    displayTree(root.left)

    displayTree(root.right)
}

function sizeOfATree(root){
    if(root===null) return 0
    
    let leftSize = sizeOfATree(root.left)
    let rightSize = sizeOfATree(root.right)
    return leftSize+rightSize+1
}

function sumOfATree(root){
    if(root===null) return 0
      
    let leftSum = sumOfATree(root.left)
    let rightSum = sumOfATree(root.right)
    return leftSum+rightSum+root.data
}

function maxOfATree(root){
    if(root===null) return -Infinity
    let leftMax = maxOfATree(root.left)
    let rightMax = maxOfATree(root.right)
    let newMax = Math.max(leftMax,rightMax)
    return Math.max(newMax,root.data)
}

function HeightOfATree(root){
    if(root===null) return 0
    let leftHeight = HeightOfATree(root.left)
    let rightHeight = HeightOfATree(root.right)
    return leftHeight>rightHeight?leftHeight+1:rightHeight+1   
}



let rootNode = createTree()
// displayTree(rootNode)
// console.log(sizeOfATree(rootNode))
// console.log(sumOfATree(rootNode))
// console.log(maxOfATree(rootNode))
console.log(HeightOfATree(rootNode))
