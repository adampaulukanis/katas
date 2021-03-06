(defpackage :cl-gol/src/game
  (:use :cl)
  (:nicknames :game)
  (:export :next-gen))

(in-package :cl-gol/src/game)

(defun next-gen (grid) 
  (let ((row_i -1))
    (map 'vector
         #'(lambda (row)
             (incf row_i)
             (new-row grid row row_i))
         grid)))

(defun new-row (grid row row-index)
  (let ((col-index -1))
    (map 'vector #'(lambda (cell)
                     (incf col-index)
                     ;(format t "col: ~a, " col-index)
                     (new-cell cell
                               col-index
                               row-index
                               grid))
         row)))

(defun new-cell (cell col-index row-index grid)
  (rules:alivep cell
                (grid:neighbour-count grid
                                      row-index
                                      col-index)))
