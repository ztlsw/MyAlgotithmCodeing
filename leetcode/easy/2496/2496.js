/**
 * @param {string[]} strs
 * @return {number}
 */
var maximumValue = function(strs) 
{
    var len = strs.length;
    var max = 0;
    for(var i = 0;i<len;i++)
    {
        var str = strs[i];
        var strLen = str.length;
        var ans = 0;
        for(var j = 0; j < strLen;j++)
        {
            if(str[j] >= 'a' && str[j] <= 'z')
            {
                ans = strLen;
                break;
            }
            ans = ans * 10 + (str[j] - '0');
        }
        max = Math.max(max,ans);
    }
    return max;
};