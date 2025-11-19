//leetcode 2704 of 30 Day js series
/**
 * @param {string} val
 * @return {Object}
 */
function expect(val) {
    return {
        toBe: function(compareVal) {
            if (val === compareVal) {
                return true;
            } else {
                throw new Error("Not Equal");
            }
        },

        notToBe: function(compareVal) {
            if (val !== compareVal) {
                return true;
            } else {
                throw new Error("Equal");
            }
        }
    };
}

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */