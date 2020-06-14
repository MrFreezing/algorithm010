学习笔记

周末才有空开始学习，课程内容比想象得多
重中之重还是要多练, 练的同时也要掌握方法和效率。
忍不住硬啃了一题接雨水，提交通过一瞬间还是挺开心的，但是一晃眼大把的时间过去了，还是不建议硬啃。


写力扣代码时，有些陷进去运行时间，
另外代码行数也很难做到最精简，感觉在力扣上，会不知不常见牺牲掉可读性，去追求更少的代码行数，这与实际工作中的规范可能是相违背的。

不过有些代码也是真的精妙，忍不住贴一下这个妖怪的代码, 这个for循环写得我目瞪口呆：

vector<int> plusOne(vector<int>& digits) {
    for (int i=digits.size(); i--; digits[i] = 0)
        if (digits[i]++ < 9)
            return digits;
    digits[0]++;
    digits.push_back(0);
    return digits;
}

https://leetcode.com/problems/plus-one/discuss/24084/Is-it-a-simple-code(C++)
