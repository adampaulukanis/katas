(defun fizz (number)
  (let ((f (mod number 3)))
    (if (= f 0)
        'yo
        'no)))

(fizz 5)

(loop for i from 0 to 100
      do
      (princ i)
      (fizz i))

(defun x ()
      (let ((fizz (= (mod i 3) 0))
            (buzz (= (mod i 5) 0)))
        (princ i)
        (if (null fizz)
            (princ "    ")
            (princ "fizz"))
        (if (null buzz)
            (princ "    ")
            (princ "buzz"))
        (fresh-line)))
