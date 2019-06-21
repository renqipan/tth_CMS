import xgboost as xgboost
#read in data
dtrain = xgb.DMatrix('demo/data/agaricus.txt.train')
dtest = xgb.DMatrix('demo/data/agaricus.txt.test')
# specify paramters via map
param={"max_depth":2,"eta":1,"silent":1,"objective":"binary:logistic"}
num_round=2
bst=xgb.train(param,dtain,num_round)
#make prediction
pred2=bst.predict(dtest)
