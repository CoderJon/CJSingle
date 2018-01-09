//
//  ViewController.m
//  SingleShare
//
//  Created by qiaohui on 2017/3/28.
//  Copyright © 2017年 znzx@QH. All rights reserved.
//

#import "ViewController.h"
#import "Tools.h"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    //注意点：单利不能使用继承
    Tools *toos = [[Tools alloc] init];
    
    Tools *t = [Tools new];
    
    NSLog(@"%p-----%p--%@----%@ ----%@",toos,t,toos,t,[Tools shareTools]);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
