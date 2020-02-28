import tensorflow as tf
sess = tf.Session()

new_saver = tf.compat.v1.train.import_meta_graph('/darkflow/ckpt/tiny-yolo-voc-2c-1000.meta')
print( new_saver)
print("hy");


#what=new_saver.restore(sess, '/home/scw4750/Liuhongkun/tfrecord/zooscan/Alexnet/Modal/model20170226041552612/mymodel')

# print(what)
# all_vars = tf.get_collection('alexnet_v2')
# print(all_vars)
# for v in all_vars:
    # v_ = sess.run(v)
    # print(v_)
    
    
