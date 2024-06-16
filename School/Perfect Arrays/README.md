<h2><a href="https://www.geeksforgeeks.org/problems/perfect-arrays4645/1?page=1&category=Arrays&difficulty=School&sortBy=submissions">Perfect Arrays</a></h2><h3>Difficulty Level : School</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr</strong> of size <strong>n</strong> and you have to tell whether the <strong>arr</strong> is perfect or not. An array is said to be perfect if its reverse array matches the original array. If the <strong>arr </strong>is perfect then return<strong> True </strong>else return<strong> False.</strong></span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input :<br></strong>n = 5<strong><br></strong>arr = {1, 2, 3, 2, 1}
<strong>Output :</strong> PERFECT
<strong>Explanation:
</strong>Here we can see we have [1, 2, 3, 2, 1] if we reverse it we can find [1, 2, 3, 2, 1]<br>which is the same as before.So, the answer is <strong>PERFECT</strong>.

</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input :<br></strong>n = 5<strong><br></strong>arr = {1, 2, 3, 4, 5}
<strong>Output :</strong> NOT PERFECT<br><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation:<br></strong>Here we can see we have [1, 2, 3, 4, 5] if we reverse it we find [5, 4, 3, 2, 1]<br>which is the not same as before.So, the answer is <strong>NOT</strong> <strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">PERFECT</strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">.</span>
</span></pre>
<p><br><span style="font-size: 18px;"><strong>User Task:</strong><br>The task is to complete the function <strong>IsPerfect()</strong>, which takes an&nbsp;array <strong>arr </strong>&nbsp;of size <strong>n , </strong>and returns the boolean value <strong>true</strong> if it is Perfect else <strong>false</strong>. The driver will print itself "<strong>PERFECT</strong>" or "<strong>NOT PERFECT</strong>" accordingly.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n).<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>6</sup><br>1 ≤ arr[i] ≤ 10<sup>9</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;