---

layout: default

title: ecg result analysis

---

[TOC]

#Meeting

* work on the open source OCR
* using training methods, like

 * learning and get the normal range
 * using possible relationship to modify the range

* do some little experiment on knowing some range of some parameters
* think about the overall architucture

#2014/3/9
##Overall Structure
* ImageJ for the pre-processing
* ABBYY(A) and tesseract(T) for the OCR engine

##Results of ABBYY on Pic2/2010
Two main problems:

* Miss-understanding the key-value structure
* Wrong in the key name

I guess the job has something to do with Information Extraction and maybe something like fuzzy matching wil be needed for key name error.

Personally, I believe results of A are better than T.

Comments on the result:

* A big problem on T is : character.
* Sometimes A and T error in the same place.
* Structure recognize error for A.
* Image quality I think is a very important factor.
 
Detailed comments:

Id  |   Comments A |   T
---|---|---
0   |   Wrong in key name (image quality) and structure, number correct.    |   Quite bad, lots of noise
2   |   Wrong for some missing in the image | Same
3   |   |   Works better on T than A （misrecognize the structure）
4   |   Bad |   Chinese
__5__   |   Error in Chinese, :, 766ms-76tos, 2.20mv-2.2Qmv, __QTC wrong(QT correct)__, lots of errors on key-value pairs |   __Some same to A__, offen replace : by other characters, seems better on T (except Chinese)
6   |   Error about structure, 146ms-1伽    |   Right on 146, 0.89-0.s9
7   |   Structure, 78-73, QTc-^Tc, |    

Classification:

* number+character
* number->character. 89-s9, range is reliable
* key name error
* structure error

##To Do
Experiment on some selected pics and try to use range to do the correction. From the result above, range may just working on 1 error and something like digit may be useful. Using possible relationship may be helpful to do the decision in a small range case (not sure).

To do the experiment, 2 things needed to be done:

* Selection
* Fuzzy matching the key name, Levenshtein Distance？

Besides, there wil be some boring adjustment I think.

#2014/3/10


