import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { ConsultaProvider } from './consulta';

import { Observable } from 'rxjs/Observable';
import { HttpClient } from '@angular/common/http';
@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

  films: Observable<any>;
  //oi:number;
  n:any;

  constructor(private navCtrl: NavController,
              private consultaProvider: ConsultaProvider,
              private httpClient: HttpClient) {    
  this.n=false;
              }

  brightness:  number = 0;

  onChange(ev:any){
    console.log('Changed',ev);
  }
  ola(x:number){
    if (this.n==false){
      this.consultaProvider.mandaLuz(x)
      .subscribe(res => console.log(res));
    }
    
    
  }

  toggle(n){
    console.log('oi ',n)
    this.consultaProvider.isAuto(n)
      .subscribe(res => console.log(res));
  }
}
