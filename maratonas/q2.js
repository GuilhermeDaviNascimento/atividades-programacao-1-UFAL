/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let n1 = "";
    l1.forEach(element => {
        n1+=element
    });
    let n2 = "";
    l2.forEach(element => {
        n2+=element
    })
    let result = Number(n1) + Number(n2);
    let result_array = []

    for (let index = result.toString().length - 1; index >= 0; index--) {
        const element = result.toString()[index];
        result_array.push(element)
    }

    console.log(result_array)
};

addTwoNumbers([2,4,3], [5,6,4])
