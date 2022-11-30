import { useState, useRef } from 'react';
import { Row, Layout, Typography, Avatar, List, Divider, Space, Button, Switch  } from 'antd';
import { HeatMapOutlined, UsergroupAddOutlined } from '@ant-design/icons';
import github from "../assets/images/github.png"
import linkedin from "../assets/images/linkedin.png"
import instagram from "../assets/images/instagram.webp"
import twitter from "../assets/images/twitter.png"

const { Footer } = Layout;
const { Title, Link } = Typography;

const data = [
    {
      title: 'Github.com',
      image: github,
      link: "https://github.com/Raiane-Dev"
    },
    {
      title: 'Linkedin',
      image: linkedin,
      link: "https://www.linkedin.com/in/raiane-dev"
    },
    {
      title: 'Instagram',
      image: instagram,
      link: "https://www.instagram.com/raiane_daros"
    },
    {
      title: 'Twitter',
      image: twitter,
      link: "https://twitter.com/RaianeDev"
    },
  ];


function _Footer(): any
{
    return(
        <>
            <Footer>
                <Row className='box'>
                    <Row>
                        <Title level={4}>
                            People who to follow. 
                            <UsergroupAddOutlined />
                        </Title>
                        <List
                            itemLayout="horizontal"
                            dataSource={data}
                            renderItem={(item) => (
                            <List.Item>
                                <List.Item.Meta
                                avatar={<Avatar size="small" src={item.image} />}
                                title={<a className='link-href' href={item.link}>{item.title}</a>}
                                />
                            </List.Item>
                            )}
                        />
                    </Row>
                </Row>

                <Row className='icon'>
                    <Divider />
                    <Title level={4}>
                        People who to follow. 
                        <UsergroupAddOutlined />
                    </Title>

                    <List
                        itemLayout="horizontal"
                        dataSource={data}
                        renderItem={(item) => (
                          <List.Item>
                            <List.Item.Meta
                              title={<a href="https://ant.design">{item.title}</a>}
                              description="03 ago"
                            />
                          </List.Item>
                        )}
                      />

                </Row>
            </Footer>
        </>
    );
}

export default _Footer;