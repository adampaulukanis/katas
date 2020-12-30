'use strict';

module.exports.fromNumber = function fromNumber (target) {
	function find(current, history){
		if (current === 0)
			return history;
		else if (current < 0)
			return null;
		else return find(current-1000, history + 'M') ||
					find(current-900, history + 'CM') ||
					find(current-500, history + 'D') ||
					find(current-400, history + 'CD') ||
					find(current-100, history + 'C') ||
					find(current-90, history + 'XC') ||
					find(current-50, history + 'L') ||
					find(current-40, history + 'XL') ||
					find(current-10, history + 'X') ||
					find(current-9, history + 'IX') ||
					find(current-5, history + 'V') ||
					find(current-4, history + 'IV') ||
					find(current-1, history + 'I');
	};

	return find(target, '');
};

